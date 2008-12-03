begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Private include for xenbus communications.  *   * Copyright (C) 2005 Rusty Russell, IBM Corporation  *  * This file may be distributed separately from the Linux kernel, or  * incorporated into other software packages, subject to the following license:  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this source file (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use, copy, modify,  * merge, publish, distribute, sublicense, and/or sell copies of the Software,  * and to permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *   * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *   * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  * IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XENBUS_COMMS_H
end_ifndef

begin_define
define|#
directive|define
name|_XENBUS_COMMS_H
end_define

begin_decl_stmt
specifier|extern
name|int
name|xen_store_evtchn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xen_store
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|xs_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xb_init_comms
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Low level routines. */
end_comment

begin_function_decl
name|int
name|xb_write
parameter_list|(
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|unsigned
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xb_read
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|unsigned
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xs_input_avail
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|xb_waitq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|xenbus_running
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|__wait_event_interruptible
parameter_list|(
name|wchan
parameter_list|,
name|condition
parameter_list|,
name|ret
parameter_list|)
define|\
value|do {								\         for (;;) {                                              \                 if (xenbus_running == 0) {			\ 			break;					\ 		}                                               \ 		if (condition)					\ 			break;					\ 		if ((ret = !tsleep(wchan, PWAIT | PCATCH, "waitev", hz/10))) \ 			break;							\ 	}									\ } while (0)
end_define

begin_define
define|#
directive|define
name|wait_event_interruptible
parameter_list|(
name|wchan
parameter_list|,
name|condition
parameter_list|)
define|\
value|({                                                                      \         int __ret = 0;                                                  \         if (!(condition))                                               \                 __wait_event_interruptible(wchan, condition, __ret);    \         __ret;                                                          \ })
end_define

begin_define
define|#
directive|define
name|DECLARE_MUTEX
parameter_list|(
name|lock
parameter_list|)
value|struct sema lock
end_define

begin_define
define|#
directive|define
name|semaphore
value|sema
end_define

begin_define
define|#
directive|define
name|rw_semaphore
value|sema
end_define

begin_define
define|#
directive|define
name|down
value|sema_wait
end_define

begin_define
define|#
directive|define
name|up
value|sema_post
end_define

begin_define
define|#
directive|define
name|down_read
value|sema_wait
end_define

begin_define
define|#
directive|define
name|up_read
value|sema_post
end_define

begin_define
define|#
directive|define
name|down_write
value|sema_wait
end_define

begin_define
define|#
directive|define
name|up_write
value|sema_post
end_define

begin_comment
comment|/**  * container_of - cast a member of a structure out to the containing structure  *  * @ptr:	the pointer to the member.  * @type:	the type of the container struct this is embedded in.  * @member:	the name of the member within the struct.  *  */
end_comment

begin_define
define|#
directive|define
name|container_of
parameter_list|(
name|ptr
parameter_list|,
name|type
parameter_list|,
name|member
parameter_list|)
value|({			\         __typeof__( ((type *)0)->member ) *__mptr = (ptr);	\         (type *)( (char *)__mptr - offsetof(type,member) );})
end_define

begin_comment
comment|/*  * XXX   *  */
end_comment

begin_define
define|#
directive|define
name|GFP_KERNEL
value|1
end_define

begin_define
define|#
directive|define
name|EXPORT_SYMBOL
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|kmalloc
parameter_list|(
name|size
parameter_list|,
name|unused
parameter_list|)
value|malloc(size, M_DEVBUF, M_WAITOK)
end_define

begin_define
define|#
directive|define
name|kfree
parameter_list|(
name|ptr
parameter_list|)
value|free((void *)(uintptr_t)ptr, M_DEVBUF)
end_define

begin_define
define|#
directive|define
name|BUG_ON
value|PANIC_IF
end_define

begin_define
define|#
directive|define
name|semaphore
value|sema
end_define

begin_define
define|#
directive|define
name|rw_semaphore
value|sema
end_define

begin_define
define|#
directive|define
name|DEFINE_SPINLOCK
parameter_list|(
name|lock
parameter_list|)
value|struct mtx lock
end_define

begin_define
define|#
directive|define
name|DECLARE_MUTEX
parameter_list|(
name|lock
parameter_list|)
value|struct sema lock
end_define

begin_define
define|#
directive|define
name|u32
value|uint32_t
end_define

begin_define
define|#
directive|define
name|list_del
parameter_list|(
name|head
parameter_list|,
name|ent
parameter_list|)
value|TAILQ_REMOVE(head, ent, list)
end_define

begin_define
define|#
directive|define
name|simple_strtoul
value|strtoul
end_define

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|x
parameter_list|)
value|(sizeof(x)/sizeof(x[0]))
end_define

begin_define
define|#
directive|define
name|list_empty
value|TAILQ_EMPTY
end_define

begin_define
define|#
directive|define
name|wake_up
value|wakeup
end_define

begin_define
define|#
directive|define
name|BUS_ID_SIZE
value|128
end_define

begin_struct
struct|struct
name|xen_bus_type
block|{
name|char
modifier|*
name|root
decl_stmt|;
name|unsigned
name|int
name|levels
decl_stmt|;
name|int
function_decl|(
modifier|*
name|get_bus_id
function_decl|)
parameter_list|(
name|char
name|bus_id
index|[
name|BUS_ID_SIZE
index|]
parameter_list|,
specifier|const
name|char
modifier|*
name|nodename
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|probe
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|,
specifier|const
name|char
modifier|*
name|dir
parameter_list|)
function_decl|;
name|struct
name|xendev_list_head
modifier|*
name|bus
decl_stmt|;
name|int
name|error
decl_stmt|;
if|#
directive|if
literal|0
block|struct bus_type bus; 	struct device dev;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|void dev_changed(const char *node, struct xen_bus_type *bus);  int  read_otherend_details(struct xenbus_device *xendev, char *id_node,  		      char *path_node);
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|kasprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XENBUS_COMMS_H */
end_comment

begin_comment
comment|/*  * Local variables:  *  c-file-style: "linux"  *  indent-tabs-mode: t  *  c-indent-level: 8  *  c-basic-offset: 8  *  tab-width: 8  * End:  */
end_comment

end_unit

