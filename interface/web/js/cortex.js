// Define cx object
cx = {
    object: function(parent, name) {
        this.parent = parent;
        this.name = name;
        this.scope = {};
        this.value = {};
        this.meta = {};
    },

    serializer: function(object, composite, collection, primitive, member, element, base) {
        this.serializeObject = object;
        this.serializeComposite = composite;
        this.serializeCollection = collection;
        this.serializePrimitive = primitive;
        this.serializeMember = member;
        this.serializeElement = element;
        this.serializeBase = base;
    },

    store: function(data) {
        var o = undefined;

        // Store object, figure out whether it is root or not
        if (!data.meta.parent || !data.meta.parent.length) {
            cx.root.meta = data.meta;
            o = cx.root;
        } else {
            parent = cx.resolve(data.meta.parent); // Assume parent is available
            if (!parent) {
                console.log("parent '" + data.meta.parent + "' not found!");
            } else {
                o = parent.declare(data.meta.name);
                o.meta = data.meta;
                o.value = data.value;
            }
        }

        // Declare all objects in the scope
        if (data.scope) {
            for (var e in data.scope) {
                var child = o.declare(data.scope[e].name);
                child.meta = data.scope[e];
                child.meta.parent = o.id();
            }
        }

        return o;      
    },

    refresh: function(data) {
        var o

        for (var i in data) {
            o = cx.store(data[i]); // Store data in JS cache
        }

        cx.me = o;

        if (cx.headerId) {
            $('#' + cx.headerId).text("");
            $('#' + cx.headerId).append(cx.toLink(o.id(), "header", true, undefined, "/"));
        }
        if (cx.metaId) {
            $('#' + cx.metaId).text("");
            $('#' + cx.metaId).append(o.metaToHtml());            
        }
        if (cx.valueId) {
            $('#' + cx.valueId).text("");
            $('#' + cx.valueId).append(o.toHtml());             
        }
        if (cx.scopeId) {
            $('#' + cx.scopeId).text("");
            $('#' + cx.scopeId).append(o.scopeToHtml());             
        }

        // Initialize table
       $("#valueTable tr[data-depth!=1]").hide();
       $("#valueTable tr[data-depth=1]").find('span.collapsing').hide();
       $("#valueTable tr[data-depth!=1]").find('span.collapsing').hide();
       $("#valueTable td.dummy").hide();
    },

    load: function(resource, success) {
        $.get(resource + "?value=true&meta=true&scope=true", success);
    },

    init: function(me, active, headerId, scopeId, metaId, valueId) {
        this.active = active;
        this.headerId = headerId;
        this.scopeId = scopeId;
        this.metaId = metaId;
        this.valueId = valueId;

        if (active) {
            cx.load("/" + me, cx.refresh);
        }
    },

    activeLink: function(url, name, style) {
        if (url.length) {
            url = url.slice(0, url.length - 1); // Remove trailing '/'
        } else {
            url = "/::";
        }

        return "<a class='" + style + 
            "' onClick='cx.load(\"" + 
                url.replace(/\"/g, "\"") + "\", cx.refresh)'>" + name + "</a>";
    },

    staticLink: function(url, name, style) {
        return "<a class='" + style + 
                "href='" + url + "index.html'>" + 
                name + "</a>";
    },

    // Convert reference string to a link
    toLinkIntern: function(link, style, fullLink, overrideName, separator, toLink) {
        var p = cx.me;
        var prefix = "";
        var result = "";
        var name = "";
        var nesting = 0;
        var i = 0;
        var itsMe = (cx.me.id() === link)

        if (!cx.active) {
            while (p.parent) {
                p = p.parent;
                prefix += "../";
            }
        }

        if (!fullLink && !(link === "::")) {
            var index = link.lastIndexOf("::");
            if (index >= 0) {
                if (index) {
                    prefix += link.slice(2, index).replace(new RegExp("\:\:", 'g'), "/") + "/";
                }
                link = link.slice(index + 2, link.length);
            }
        }

        if (style === undefined) {
            style = 'reference';
        }

        for (i = 0, start = 0; i < link.length; i++) {
            var ch = link[i];
            if (!nesting && (ch === ':')) {
                if (i === 0) {
                    if (overrideName && link.length === 2) {
                        result = toLink(prefix, overrideName, style);
                    } else {
                        result = toLink(prefix, "::", style);
                    }
                } else {
                    name = link.slice(start, i);
                    if (!separator) {
                        if (start > 2) {
                            result += "::";
                        }
                    } else {
                        result += "&nbsp;" + separator + "&nbsp;";
                    }
                    prefix += name + "/";
                    result += toLink(prefix, name, style);
                }
                i++;
                start = i + 1;
            } else if ((ch === '(') || (ch === '{')) {
                nesting++;
            } else if ((ch === ')') || (ch === '}')) {
                nesting--;
            }
        }

        name = link.slice(start, i);

        if (name.length) {
            prefix += name + "/";
            if (!separator) {
                if (start > 2) {
                    result += "::";
                }
            } else {
                result += "&nbsp;" + separator + "&nbsp;";
            }

            if (overrideName) {
                name = overrideName;
            }

            if (itsMe && fullLink) {
                result += "<span class='me'>" + name + "</span>";
            } else {
                result += toLink(prefix, name, style);
            }
        }
        return result;        
    },

    toLink: function(link, style, fullLink, name, separator) {
        if (cx.active) {
            return cx.toLinkIntern(link, style, fullLink, name, separator, cx.activeLink);
        } else {
            return cx.toLinkIntern(link, style, fullLink, name, separator, cx.staticLink);
        }
    },

    primitiveToString: function(v) {
        function getValueClass(valueKind) {
            if (valueKind === 'E') {
                return 'enum';
            } else if (valueKind === 'R') {
                return 'reference';
            } else if (valueKind === 'B') {
                return 'binary';
            } else if (valueKind === 'M') {
                return 'bitmask';
            }
        }

        var valueClass = "";
        var valueString = v;

        valueClass = typeof v;

        if ((valueClass === 'string') && (v[0] === '@')) {
            if (v[1] === '@') {
                valueString = v.substr(1, valueString.length - 1);
            } else {
                valueString = v.substr(3, valueString.length - 3);
                valueClass = getValueClass(v.substr(1, 1));
                if (valueClass == 'reference') {
                    valueClass = 'normal';
                    valueString = cx.toLink(valueString, "reference", true);
                }
            }
        }

        if (valueClass === 'string') {
            valueString = "\"" + valueString + "\"";
        }

        return "<code class=" + valueClass + ">" + valueString + "</code>";
    },

    toString: function(v) {
        function primitive(s, v) {
            return cx.primitiveToString(v);
        }

        function composite(s, v) {
            s.count = 0;
            return "{" + s.serializeMembers(v) + "}";
        }

        function collection(s, v) {
            s.count = 0;
            return "{" + s.serializeElements(v) + "}";
        }

        function member(s, v) {
            var result = "";
            if (s.count > 0) {
                result = " ";
            }
            s.count++;
            return result + s.info + "=" + s.serializeValue(v);
        }

        function element(s, v) {
            var result = "";
            if (s.count > 0) {
                result = ", ";
            }
            s.count++;
            return result + s.serializeValue(v);
        }

        var s = new cx.serializer(
            undefined, composite, collection, primitive, member, element
        )
        s.count = 0;
        return "<code>" + s.serialize(v) + "</code>";   
    }
}

// Define cx.serializer prototype
cx.serializer.prototype = {

    serializeValue: function(o) {
        if (o instanceof Array) {
            return this.serializeCollection(this, o);
        } else if (o instanceof Object) {
            return this.serializeComposite(this, o);
        } else {
            return this.serializePrimitive(this, o);
        }
    },

    serializeMembers: function(o) {
        var result = "";
        for (var k in o) {
            if (k[0] != '@') {
                this.info = k;
                result += this.serializeMember(this, o[k]);
            } else {
                this.info = k.slice(1, k.length);
                result += this.serializeBase(this, o[k]);
            }
        }
        return result;
    },

    serializeElements: function(o) {
        var result = "";
        o.forEach(function (item, i) {
            this.info = i;
            result += this.serializeElement(this, item);
        }, this);
        return result;
    },

    serialize: function(o) {
        this.info = undefined;
        if (this.serializeComposite === undefined) {
            this.serializeComposite = function(s, o) {return s.serializeMembers(o)};
        }
        if (this.serializeCollection === undefined) {
            this.serializeCollection = function(s, o) {return s.serializeElements(o)};
        }
        if (this.serializeMember === undefined) {
            this.serializeMember = function(s, o) {return s.serializeValue(o)};
        }
        if (this.serializeElement === undefined) {
            this.serializeElement = function(s, o) {return s.serializeValue(o)};
        }
        if (this.serializeObject === undefined) {
            this.serializeObject = function(s, o) {return s.serializeValue(o)};
        }
        if (this.serializeBase === undefined) {
            this.serializeBase = function(s, o) {return s.serializeValue(o)};
        }
        return this.serializeObject(this, o);
    }
};

// Define cx.object prototype
cx.object.prototype = {

    // Return id of object (fully scoped name)
    id: function() {
        var result = this.meta.name;

        if (this.meta.parent) {
            if (this.meta.parent !== "::") {
                result = this.meta.parent + "::" + this.meta.name
            } else {
                result = "::" + this.meta.name;
            }
        }

        return result;
    },

    // Resolve object
    // This method must be used with caution. The JS cache is not a complete
    // copy of the cortex store. Resolve will only work for objects currently
    // present in the store.
    resolve: function(fullname) {
        var scope = this;
        var o = undefined;

        if (fullname == "::") {
            o = cx.root;
        } else {

            for (var i = 0, start = 0; i < fullname.length; i++) {
                var ch = fullname[i];
                if (ch === ':') {
                    if (i === 0) {
                        scope = cx.root;
                    } else {
                        var name = fullname.slice(start, i);
                        scope = scope.scope[name];
                        if (scope === undefined) {
                            break;
                        }
                    }
                    i++;
                    start = i + 1;
                }
            }

            o = scope.scope[fullname.slice(start, i)];

            if ((o === undefined) && (this.parent !== undefined)) {
                console.log("continue searching for '" + fullname + "' on " + scope.parent.id() + " (scope = " + scope.id());
                o = this.parent.resolve(fullname);
            }
        }

        return o;
    },

    // Declare a new object
    declare: function(name) {
        var o = this.scope[name];
        if (o == undefined) {
            var o = new cx.object(this, name);
            this.scope[name] = o;
        }
        return o;
    },

    // Convert scope to HTML
    scopeToHtml: function() {
        var result = "";
        var link = "";
        var links = [];
        var size = 0;

        result = "<table id='scopeTable' class='value'>";
        result += "<thead class='value'><tr><td><h3>Scope<img id='scopeIcon'></img></h3></td></tr></thead>";
        result += "<tbody class='value'>";
        result += "<tr><td><div id='scopeContent'><table>";

        if (this.parent) {
            result += "<tr>" + 
                    "<td><img id='upIcon'>" + 
                    cx.toLink(this.parent.id(), "reference", false, "..") + 
                    "</td>" +
                    "</tr>";
        }

        for (o in this.scope) { size++; }
        if (size) {
            for (o in this.scope) {
                result += "<tr>" + 
                    "<td><img id='objectIcon'></img>" + 
                    cx.toLink(this.scope[o].id()) + 
                    "<span class='scopeType'>&nbsp;&#8226;&nbsp;" + 
                    cx.toLink(this.scope[o].meta.type, "scopeType") + 
                    "</span></td>" +
                    "</tr>";
            }
        } else {
            result += "<tr><td></td></tr>";
        }
        result += "</table></div></td></tr>";
        result += "<tr><td></td></tr></tbody>";

        return result;
    },

    // Convert metadata to HTML
    metaToHtml: function() {
        function parseStates(states) {
            var buffer = "";
            buffer = states.replace(/V/, "valid");
            buffer = buffer.replace(/DCL/, "declared");
            buffer = buffer.replace(/DEF/, "defined");
            return buffer;
        }

        function parseAttr(attributes) {
            var buffer = "";
            buffer = attributes.replace(/S/, "scoped");
            buffer = buffer.replace(/W/, "writable");
            buffer = buffer.replace(/O/, "observable");
            return buffer;
        }

        var result = "";
        result += "<table id='metaTable' class='value'>";
        result += "<thead class='value'><tr><th></th><td><h3>Metadata<img id='metaIcon'></img></h3></td></tr></thead><tbody class='value'>"
        result += "<tr><th>type</th>" + 
                      "<td><code>" + cx.toLink(this.meta.type, "reference", true) + "</code></td>";
        if (this.meta.parent) {
            result += "<tr><th>parent</th>" +
                      "<td><code>" + cx.toLink(this.meta.parent) + "</code></td>";
        }
        result += "<tr><th>state</th>" +
                      "<td><code class='bitmask'>" + parseStates(this.meta.states) + "</code></td></tr>";
        result += "<tr><th>attributes</th>" +
                      "<td><code class='bitmask'>" + parseAttr(this.meta.attributes) + "</code></td></tr>";
        result += "</tbody></table>";
        return result;
    },

    // Convert object value to HTML
    toHtml: function() {

        function primitive(s, v) {
            return cx.primitiveToString(v);
        }

        function indent(level) {
            var result = "<span style='font-family: monospace;'>";
            for(var i = 0; i < (level-1); i++) {
                result += "&nbsp;";
            }
            result += "</span>";
            return result;
        }

        function arrow() {
            return "<span class='expanding'>&#9654</span><span class='collapsing'>&#9660;</span>"
        }

        function memberString(level, name, isObject) {
            var result = "";
            if (isObject) {
                result = indent(level) + arrow() + "&nbsp;" + name;
            } else {
                result = indent(level) + name;
            }
            return result;
        }

        function member(s, v) {
            var result = "";

            if (v instanceof Object) {
                collapse = "class='expanding toggle'";
                result = "<tr " + collapse + " data-depth='" + s.level + "'><th>" + 
                    memberString(s.level, s.info, true) + "</th><td class='dummy'></td><td class='complex'>" + 
                    cx.toString(v) +
                    "</td></tr>";
                s.level++;
                result += s.serializeValue(v);
                s.level--;
            } else {
                collapse = "class='expanding'";
                result = "<tr " + collapse + " data-depth='" + s.level + "'><th>" + 
                    memberString(s.level, s.info, false) + "</th><td>" + s.serializeValue(v) + "</td></tr>";
            }
            
            return result;
        }

        function base(s, v) {
            var result = "";
            s.baseArray.push(s.info);
            result = s.serializeValue(v);
            if (!s.baseAdded) {
                result = "<tr data-depth='1'><th class='base'></th><td class='base'>inherited from " + 
                    s.baseArray[s.baseArray.length - 1] + "</td></tr>" + result;
                s.baseArray.pop();
            }

            result = result + "<tr data-depth='1'><th class='base'></th><td class='base'>inherited from " + 
                s.baseArray[s.baseArray.length - 1] + "</td></tr>";
            s.baseArray.pop();

            s.baseAdded++;

            return result;
        }

        function object(s, v) {
            var result = "";
            var size = 0;

            s.level = 1;
            s.baseArray = [ s.me.meta.type ];
            s.baseAdded = 0;

            if (typeof v == 'object') {
                for (k in v) {size ++;}
            } else {
                size = 1;
            }

            result += "<table id='valueTable' class='value'>";
            result += "<thead class='value'><tr data-depth='1'>" + 
                      "<th></th><td><h3>Value<img id='valueIcon'></img></h3></td></tr></thead><tbody class='value'>";
            if (size) {
                var value = s.serializeValue(v);
                if (!(v instanceof Object)) {
                    value = "<tr data-depth='1'><th class='value'></th>" + "<td>" + value + "</td></tr>";
                }
                result += value;
            } else {
                result += "<tr data-depth='1'><th></th><td><code>empty</code></td></tr>";
            }
            result += "</tbody></table>";
            result += "\
<script> \
$(function() { \
    $('#valueTable').on('click', '.toggle', function () { \
        console.log('click event!');\
        var findChildren = function (tr) { \
            var depth = tr.data('depth'); \
            return tr.nextUntil($('tr').filter(function () { \
                return $(this).data('depth') <= depth; \
            })); \
        }; \
\
        var el = $(this); \
        var tr = el.closest('tr'); \
        var children = findChildren(tr); \
\
        var subnodes = children.filter('.expanding'); \
        subnodes.each(function () { \
            var subnode = $(this); \
            var subnodeChildren = findChildren(subnode); \
            children = children.not(subnodeChildren); \
        }); \
\
        if (tr.hasClass('collapsing')) { \
            tr.removeClass('collapsing').addClass('expanding'); \
            tr.find('span.collapsing').hide(); \
            tr.find('span.expanding').show(); \
            tr.find('td.complex').show(); \
            tr.find('td.dummy').hide(); \
            children.hide(); \
        } else { \
            tr.find('span.collapsing').show(); \
            tr.find('span.expanding').hide(); \
            tr.find('td.complex').hide(); \
            tr.find('td.dummy').show(); \
            tr.removeClass('expanding').addClass('collapsing'); \
            children.show(); \
        } \
        return children; \
    }); \
});\
</script>"

            return result;
        }

        var s = new cx.serializer(
            object, undefined, undefined, primitive, member, member, base
        )
        s.me = this;
        return s.serialize(this.value);
    }
}

// Create the root object
cx.root = new cx.object(undefined, "");
cx.root.meta.type = "::cortex::lang::object";

// Create a resolve in cx that resolves from root
cx.resolve = function(name) { return cx.root.resolve(name);}




