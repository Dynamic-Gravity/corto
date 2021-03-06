/*
 * corto_load.h
 *
 *  Created on: Aug 6, 2012
 *      Author: sander
 */

#ifndef CORTO_CORE_META_H_
#define CORTO_CORE_META_H_

#include "corto/lang/_type.h"
#include "corto/core/_type.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CORTO_META_OBJECT(type, name) CORTO_EXPORT extern corto_##type corto_##name##_o

CORTO_EXPORT extern corto_package root_o;
CORTO_EXPORT extern corto_package corto_o;
CORTO_EXPORT extern corto_package corto_core_o;

/* Forward declarations of classes */
CORTO_META_OBJECT(class, package);
CORTO_META_OBJECT(class, application);
CORTO_META_OBJECT(class, tool);
CORTO_META_OBJECT(class, router);
CORTO_META_OBJECT(class, routerimpl);
CORTO_META_OBJECT(class, mount);
CORTO_META_OBJECT(struct, mountStats);
CORTO_META_OBJECT(struct, mountPolicy);
CORTO_META_OBJECT(struct, mountSubscription);
CORTO_META_OBJECT(class, loader);
CORTO_META_OBJECT(class, stager);
CORTO_META_OBJECT(struct, result);
CORTO_META_OBJECT(struct, request);
CORTO_META_OBJECT(struct, frame);
CORTO_META_OBJECT(struct, query);
CORTO_META_OBJECT(interface, dispatcher);

CORTO_META_OBJECT(enum, equalityKind);
CORTO_META_OBJECT(enum, operatorKind);
CORTO_META_OBJECT(bitmask, eventMask);
CORTO_META_OBJECT(bitmask, resultMask);
CORTO_META_OBJECT(enum, ownership);
CORTO_META_OBJECT(bitmask, mountMask);
CORTO_META_OBJECT(enum, frameKind);

CORTO_META_OBJECT(list, resultList);
CORTO_META_OBJECT(list, mountSubscriptionList);
CORTO_META_OBJECT(sequence, augmentseq);

CORTO_META_OBJECT(delegate, notifyAction);
CORTO_META_OBJECT(delegate, invokeAction);
CORTO_META_OBJECT(delegate, requestAction);
CORTO_META_OBJECT(delegate, handleAction);

CORTO_META_OBJECT(procedure, remote);
CORTO_META_OBJECT(procedure, subscriber);
CORTO_META_OBJECT(procedure, observer);
CORTO_META_OBJECT(procedure, route);

CORTO_META_OBJECT(struct, event);
CORTO_META_OBJECT(struct, observerEvent);
CORTO_META_OBJECT(struct, position);
CORTO_META_OBJECT(struct, sample);
CORTO_META_OBJECT(struct, subscriberEvent);
CORTO_META_OBJECT(struct, invokeEvent);
CORTO_META_OBJECT(struct, time);

CORTO_META_OBJECT(subscriber, mount_on_notify);

CORTO_META_OBJECT(iterator, resultIter);
CORTO_META_OBJECT(iterator, sampleIter);
CORTO_META_OBJECT(iterator, subscriberEventIter);

CORTO_META_OBJECT(function, observerEvent_handle);
CORTO_META_OBJECT(function, subscriberEvent_handle);

#ifdef __cplusplus
}
#endif

#endif /* CORTO_META_H_ */
