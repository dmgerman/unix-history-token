begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * ring.h  *   * Shared producer-consumer ring macros.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Tim Deegan and Andrew Warfield November 2004.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_IO_RING_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_IO_RING_H__
end_define

begin_include
include|#
directive|include
file|"../xen-compat.h"
end_include

begin_if
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|<
literal|0x00030208
end_if

begin_define
define|#
directive|define
name|xen_mb
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|xen_rmb
parameter_list|()
value|rmb()
end_define

begin_define
define|#
directive|define
name|xen_wmb
parameter_list|()
value|wmb()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|int
name|RING_IDX
typedef|;
end_typedef

begin_comment
comment|/* Round a 32-bit unsigned constant down to the nearest power of two. */
end_comment

begin_define
define|#
directive|define
name|__RD2
parameter_list|(
name|_x
parameter_list|)
value|(((_x)& 0x00000002) ? 0x2                  : ((_x)& 0x1))
end_define

begin_define
define|#
directive|define
name|__RD4
parameter_list|(
name|_x
parameter_list|)
value|(((_x)& 0x0000000c) ? __RD2((_x)>>2)<<2    : __RD2(_x))
end_define

begin_define
define|#
directive|define
name|__RD8
parameter_list|(
name|_x
parameter_list|)
value|(((_x)& 0x000000f0) ? __RD4((_x)>>4)<<4    : __RD4(_x))
end_define

begin_define
define|#
directive|define
name|__RD16
parameter_list|(
name|_x
parameter_list|)
value|(((_x)& 0x0000ff00) ? __RD8((_x)>>8)<<8    : __RD8(_x))
end_define

begin_define
define|#
directive|define
name|__RD32
parameter_list|(
name|_x
parameter_list|)
value|(((_x)& 0xffff0000) ? __RD16((_x)>>16)<<16 : __RD16(_x))
end_define

begin_comment
comment|/*  * Calculate size of a shared ring, given the total available space for the  * ring and indexes (_sz), and the name tag of the request/response structure.  * A ring contains as many entries as will fit, rounded down to the nearest   * power of two (so we can mask with (size-1) to loop around).  */
end_comment

begin_define
define|#
directive|define
name|__RING_SIZE
parameter_list|(
name|_s
parameter_list|,
name|_sz
parameter_list|)
define|\
value|(__RD32(((_sz) - (long)(_s)->ring + (long)(_s)) / sizeof((_s)->ring[0])))
end_define

begin_comment
comment|/*  * Macros to make the correct C datatypes for a new kind of ring.  *   * To make a new ring datatype, you need to have two message structures,  * let's say request_t, and response_t already defined.  *  * In a header where you want the ring datatype declared, you then do:  *  *     DEFINE_RING_TYPES(mytag, request_t, response_t);  *  * These expand out to give you a set of types, as you can see below.  * The most important of these are:  *   *     mytag_sring_t      - The shared ring.  *     mytag_front_ring_t - The 'front' half of the ring.  *     mytag_back_ring_t  - The 'back' half of the ring.  *  * To initialize a ring in your code you need to know the location and size  * of the shared memory area (PAGE_SIZE, for instance). To initialise  * the front half:  *  *     mytag_front_ring_t front_ring;  *     SHARED_RING_INIT((mytag_sring_t *)shared_page);  *     FRONT_RING_INIT(&front_ring, (mytag_sring_t *)shared_page, PAGE_SIZE);  *  * Initializing the back follows similarly (note that only the front  * initializes the shared ring):  *  *     mytag_back_ring_t back_ring;  *     BACK_RING_INIT(&back_ring, (mytag_sring_t *)shared_page, PAGE_SIZE);  */
end_comment

begin_define
define|#
directive|define
name|DEFINE_RING_TYPES
parameter_list|(
name|__name
parameter_list|,
name|__req_t
parameter_list|,
name|__rsp_t
parameter_list|)
define|\                                                                         \
comment|/* Shared ring entry */
define|\
value|union __name##_sring_entry {                                            \     __req_t req;                                                        \     __rsp_t rsp;                                                        \ };                                                                      \                                                                         \
comment|/* Shared ring page */
value|\ struct __name##_sring {                                                 \     RING_IDX req_prod, req_event;                                       \     RING_IDX rsp_prod, rsp_event;                                       \     uint8_t  pad[48];                                                   \     union __name##_sring_entry ring[1];
comment|/* variable-length */
value|\ };                                                                      \                                                                         \
comment|/* "Front" end's private variables */
value|\ struct __name##_front_ring {                                            \     RING_IDX req_prod_pvt;                                              \     RING_IDX rsp_cons;                                                  \     unsigned int nr_ents;                                               \     struct __name##_sring *sring;                                       \ };                                                                      \                                                                         \
comment|/* "Back" end's private variables */
value|\ struct __name##_back_ring {                                             \     RING_IDX rsp_prod_pvt;                                              \     RING_IDX req_cons;                                                  \     unsigned int nr_ents;                                               \     struct __name##_sring *sring;                                       \ };                                                                      \                                                                         \
comment|/* Syntactic sugar */
value|\ typedef struct __name##_sring __name##_sring_t;                         \ typedef struct __name##_front_ring __name##_front_ring_t;               \ typedef struct __name##_back_ring __name##_back_ring_t
end_define

begin_comment
comment|/*  * Macros for manipulating rings.  *   * FRONT_RING_whatever works on the "front end" of a ring: here   * requests are pushed on to the ring and responses taken off it.  *   * BACK_RING_whatever works on the "back end" of a ring: here   * requests are taken off the ring and responses put on.  *   * N.B. these macros do NO INTERLOCKS OR FLOW CONTROL.   * This is OK in 1-for-1 request-response situations where the   * requestor (front end) never has more than RING_SIZE()-1  * outstanding requests.  */
end_comment

begin_comment
comment|/* Initialising empty rings */
end_comment

begin_define
define|#
directive|define
name|SHARED_RING_INIT
parameter_list|(
name|_s
parameter_list|)
value|do {                                       \     (_s)->req_prod  = (_s)->rsp_prod  = 0;                              \     (_s)->req_event = (_s)->rsp_event = 1;                              \     (void)memset((_s)->pad, 0, sizeof((_s)->pad));                      \ } while(0)
end_define

begin_define
define|#
directive|define
name|FRONT_RING_INIT
parameter_list|(
name|_r
parameter_list|,
name|_s
parameter_list|,
name|__size
parameter_list|)
value|do {                            \     (_r)->req_prod_pvt = 0;                                             \     (_r)->rsp_cons = 0;                                                 \     (_r)->nr_ents = __RING_SIZE(_s, __size);                            \     (_r)->sring = (_s);                                                 \ } while (0)
end_define

begin_define
define|#
directive|define
name|BACK_RING_INIT
parameter_list|(
name|_r
parameter_list|,
name|_s
parameter_list|,
name|__size
parameter_list|)
value|do {                             \     (_r)->rsp_prod_pvt = 0;                                             \     (_r)->req_cons = 0;                                                 \     (_r)->nr_ents = __RING_SIZE(_s, __size);                            \     (_r)->sring = (_s);                                                 \ } while (0)
end_define

begin_comment
comment|/* Initialize to existing shared indexes -- for recovery */
end_comment

begin_define
define|#
directive|define
name|FRONT_RING_ATTACH
parameter_list|(
name|_r
parameter_list|,
name|_s
parameter_list|,
name|__size
parameter_list|)
value|do {                          \     (_r)->sring = (_s);                                                 \     (_r)->req_prod_pvt = (_s)->req_prod;                                \     (_r)->rsp_cons = (_s)->rsp_prod;                                    \     (_r)->nr_ents = __RING_SIZE(_s, __size);                            \ } while (0)
end_define

begin_define
define|#
directive|define
name|BACK_RING_ATTACH
parameter_list|(
name|_r
parameter_list|,
name|_s
parameter_list|,
name|__size
parameter_list|)
value|do {                           \     (_r)->sring = (_s);                                                 \     (_r)->rsp_prod_pvt = (_s)->rsp_prod;                                \     (_r)->req_cons = (_s)->req_prod;                                    \     (_r)->nr_ents = __RING_SIZE(_s, __size);                            \ } while (0)
end_define

begin_comment
comment|/* How big is this ring? */
end_comment

begin_define
define|#
directive|define
name|RING_SIZE
parameter_list|(
name|_r
parameter_list|)
define|\
value|((_r)->nr_ents)
end_define

begin_comment
comment|/* Number of free requests (for use on front side only). */
end_comment

begin_define
define|#
directive|define
name|RING_FREE_REQUESTS
parameter_list|(
name|_r
parameter_list|)
define|\
value|(RING_SIZE(_r) - ((_r)->req_prod_pvt - (_r)->rsp_cons))
end_define

begin_comment
comment|/* Test if there is an empty slot available on the front ring.  * (This is only meaningful from the front. )  */
end_comment

begin_define
define|#
directive|define
name|RING_FULL
parameter_list|(
name|_r
parameter_list|)
define|\
value|(RING_FREE_REQUESTS(_r) == 0)
end_define

begin_comment
comment|/* Test if there are outstanding messages to be processed on a ring. */
end_comment

begin_define
define|#
directive|define
name|RING_HAS_UNCONSUMED_RESPONSES
parameter_list|(
name|_r
parameter_list|)
define|\
value|((_r)->sring->rsp_prod - (_r)->rsp_cons)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|RING_HAS_UNCONSUMED_REQUESTS
parameter_list|(
name|_r
parameter_list|)
value|({                             \     unsigned int req = (_r)->sring->req_prod - (_r)->req_cons;          \     unsigned int rsp = RING_SIZE(_r) -                                  \         ((_r)->req_cons - (_r)->rsp_prod_pvt);                          \     req< rsp ? req : rsp;                                              \ })
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Same as above, but without the nice GCC ({ ... }) syntax. */
end_comment

begin_define
define|#
directive|define
name|RING_HAS_UNCONSUMED_REQUESTS
parameter_list|(
name|_r
parameter_list|)
define|\
value|((((_r)->sring->req_prod - (_r)->req_cons)<                        \       (RING_SIZE(_r) - ((_r)->req_cons - (_r)->rsp_prod_pvt))) ?        \      ((_r)->sring->req_prod - (_r)->req_cons) :                         \      (RING_SIZE(_r) - ((_r)->req_cons - (_r)->rsp_prod_pvt)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Direct access to individual ring elements, by index. */
end_comment

begin_define
define|#
directive|define
name|RING_GET_REQUEST
parameter_list|(
name|_r
parameter_list|,
name|_idx
parameter_list|)
define|\
value|(&((_r)->sring->ring[((_idx)& (RING_SIZE(_r) - 1))].req))
end_define

begin_define
define|#
directive|define
name|RING_GET_RESPONSE
parameter_list|(
name|_r
parameter_list|,
name|_idx
parameter_list|)
define|\
value|(&((_r)->sring->ring[((_idx)& (RING_SIZE(_r) - 1))].rsp))
end_define

begin_comment
comment|/* Loop termination condition: Would the specified index overflow the ring? */
end_comment

begin_define
define|#
directive|define
name|RING_REQUEST_CONS_OVERFLOW
parameter_list|(
name|_r
parameter_list|,
name|_cons
parameter_list|)
define|\
value|(((_cons) - (_r)->rsp_prod_pvt)>= RING_SIZE(_r))
end_define

begin_define
define|#
directive|define
name|RING_PUSH_REQUESTS
parameter_list|(
name|_r
parameter_list|)
value|do {                                     \     xen_wmb();
comment|/* back sees requests /before/ updated producer index */
value|\     (_r)->sring->req_prod = (_r)->req_prod_pvt;                         \ } while (0)
end_define

begin_define
define|#
directive|define
name|RING_PUSH_RESPONSES
parameter_list|(
name|_r
parameter_list|)
value|do {                                    \     xen_wmb();
comment|/* front sees resps /before/ updated producer index */
value|\     (_r)->sring->rsp_prod = (_r)->rsp_prod_pvt;                         \ } while (0)
end_define

begin_comment
comment|/*  * Notification hold-off (req_event and rsp_event):  *   * When queueing requests or responses on a shared ring, it may not always be  * necessary to notify the remote end. For example, if requests are in flight  * in a backend, the front may be able to queue further requests without  * notifying the back (if the back checks for new requests when it queues  * responses).  *   * When enqueuing requests or responses:  *   *  Use RING_PUSH_{REQUESTS,RESPONSES}_AND_CHECK_NOTIFY(). The second argument  *  is a boolean return value. True indicates that the receiver requires an  *  asynchronous notification.  *   * After dequeuing requests or responses (before sleeping the connection):  *   *  Use RING_FINAL_CHECK_FOR_REQUESTS() or RING_FINAL_CHECK_FOR_RESPONSES().  *  The second argument is a boolean return value. True indicates that there  *  are pending messages on the ring (i.e., the connection should not be put  *  to sleep).  *   *  These macros will set the req_event/rsp_event field to trigger a  *  notification on the very next message that is enqueued. If you want to  *  create batches of work (i.e., only receive a notification after several  *  messages have been enqueued) then you will need to create a customised  *  version of the FINAL_CHECK macro in your own code, which sets the event  *  field appropriately.  */
end_comment

begin_define
define|#
directive|define
name|RING_PUSH_REQUESTS_AND_CHECK_NOTIFY
parameter_list|(
name|_r
parameter_list|,
name|_notify
parameter_list|)
value|do {           \     RING_IDX __old = (_r)->sring->req_prod;                             \     RING_IDX __new = (_r)->req_prod_pvt;                                \     xen_wmb();
comment|/* back sees requests /before/ updated producer index */
value|\     (_r)->sring->req_prod = __new;                                      \     xen_mb();
comment|/* back sees new requests /before/ we check req_event */
value|\     (_notify) = ((RING_IDX)(__new - (_r)->sring->req_event)<           \                  (RING_IDX)(__new - __old));                            \ } while (0)
end_define

begin_define
define|#
directive|define
name|RING_PUSH_RESPONSES_AND_CHECK_NOTIFY
parameter_list|(
name|_r
parameter_list|,
name|_notify
parameter_list|)
value|do {          \     RING_IDX __old = (_r)->sring->rsp_prod;                             \     RING_IDX __new = (_r)->rsp_prod_pvt;                                \     xen_wmb();
comment|/* front sees resps /before/ updated producer index */
value|\     (_r)->sring->rsp_prod = __new;                                      \     xen_mb();
comment|/* front sees new resps /before/ we check rsp_event */
value|\     (_notify) = ((RING_IDX)(__new - (_r)->sring->rsp_event)<           \                  (RING_IDX)(__new - __old));                            \ } while (0)
end_define

begin_define
define|#
directive|define
name|RING_FINAL_CHECK_FOR_REQUESTS
parameter_list|(
name|_r
parameter_list|,
name|_work_to_do
parameter_list|)
value|do {             \     (_work_to_do) = RING_HAS_UNCONSUMED_REQUESTS(_r);                   \     if (_work_to_do) break;                                             \     (_r)->sring->req_event = (_r)->req_cons + 1;                        \     xen_mb();                                                           \     (_work_to_do) = RING_HAS_UNCONSUMED_REQUESTS(_r);                   \ } while (0)
end_define

begin_define
define|#
directive|define
name|RING_FINAL_CHECK_FOR_RESPONSES
parameter_list|(
name|_r
parameter_list|,
name|_work_to_do
parameter_list|)
value|do {            \     (_work_to_do) = RING_HAS_UNCONSUMED_RESPONSES(_r);                  \     if (_work_to_do) break;                                             \     (_r)->sring->rsp_event = (_r)->rsp_cons + 1;                        \     xen_mb();                                                           \     (_work_to_do) = RING_HAS_UNCONSUMED_RESPONSES(_r);                  \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_IO_RING_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

