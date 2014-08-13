begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2011 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_KERNEL_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSD_KERNEL_H_
end_define

begin_define
define|#
directive|define
name|_KERNEL
end_define

begin_define
define|#
directive|define
name|__FreeBSD_version
value|1000000
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|x
parameter_list|)
value|(((x)>= 'a'&& (x)<= 'z') || ((x)>= 'A'&& (x)<= 'Z'))
end_define

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|x
parameter_list|)
value|((x)>= '0'&& (x)<= '9')
end_define

begin_define
define|#
directive|define
name|panic
parameter_list|(
modifier|...
parameter_list|)
value|do { printf("USB PANIC: " __VA_ARGS__); while (1) ; } while (0)
end_define

begin_define
define|#
directive|define
name|rebooting
value|0
end_define

begin_define
define|#
directive|define
name|M_USB
value|0
end_define

begin_define
define|#
directive|define
name|M_USBDEV
value|0
end_define

begin_define
define|#
directive|define
name|USB_PROC_MAX
value|3
end_define

begin_define
define|#
directive|define
name|USB_BUS_GIANT_PROC
parameter_list|(
name|bus
parameter_list|)
value|(usb_process + 2)
end_define

begin_define
define|#
directive|define
name|USB_BUS_NON_GIANT_PROC
parameter_list|(
name|bus
parameter_list|)
value|(usb_process + 2)
end_define

begin_define
define|#
directive|define
name|USB_BUS_EXPLORE_PROC
parameter_list|(
name|bus
parameter_list|)
value|(usb_process + 0)
end_define

begin_define
define|#
directive|define
name|USB_BUS_CONTROL_XFER_PROC
parameter_list|(
name|bus
parameter_list|)
value|(usb_process + 1)
end_define

begin_define
define|#
directive|define
name|SYSCTL_DECL
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SYSCTL_NODE
parameter_list|(
name|name
parameter_list|,
modifier|...
parameter_list|)
value|struct { } name __used
end_define

begin_define
define|#
directive|define
name|SYSCTL_INT
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|TUNABLE_INT
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MALLOC_DECLARE
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MALLOC_DEFINE
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|EVENTHANDLER_DECLARE
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|EVENTHANDLER_INVOKE
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|KASSERT
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SCHEDULER_STOPPED
parameter_list|(
name|x
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|PI_SWI
parameter_list|(
modifier|...
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|UNIQ_NAME
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|UNIQ_NAME_STR
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_define
define|#
directive|define
name|DEVCLASS_MAXUNIT
value|32
end_define

begin_define
define|#
directive|define
name|MOD_LOAD
value|1
end_define

begin_define
define|#
directive|define
name|MOD_UNLOAD
value|2
end_define

begin_define
define|#
directive|define
name|DEVMETHOD
parameter_list|(
name|what
parameter_list|,
name|func
parameter_list|)
value|{ #what, (void *)&func }
end_define

begin_define
define|#
directive|define
name|DEVMETHOD_END
value|{0,0}
end_define

begin_define
define|#
directive|define
name|DRIVER_MODULE
parameter_list|(
name|name
parameter_list|,
name|busname
parameter_list|,
name|driver
parameter_list|,
name|devclass
parameter_list|,
name|evh
parameter_list|,
name|arg
parameter_list|)
define|\
value|static struct module_data bsd_##name##_##busname##_driver_mod = {	\ 	evh, arg, #busname, #name, #busname "/" #name,			\&driver,&devclass, { 0, 0 } };					\ SYSINIT(bsd_##name##_##busname##_driver_mod, SI_SUB_DRIVERS,		\   SI_ORDER_MIDDLE, module_register,					\&bsd_##name##_##busname##_driver_mod)
end_define

begin_define
define|#
directive|define
name|SYSINIT
parameter_list|(
name|uniq
parameter_list|,
name|subs
parameter_list|,
name|order
parameter_list|,
name|_func
parameter_list|,
name|_data
parameter_list|)
define|\
value|const struct sysinit UNIQ_NAME(sysinit_##uniq) = {	\ 	.func = (_func),				\ 	.data = __DECONST(void *, _data)		\ };							\ SYSINIT_ENTRY(uniq##_entry, "sysinit", (subs),		\     (order), "const struct sysinit",			\     UNIQ_NAME_STR(sysinit_##uniq), "SYSINIT")
end_define

begin_define
define|#
directive|define
name|SYSUNINIT
parameter_list|(
name|uniq
parameter_list|,
name|subs
parameter_list|,
name|order
parameter_list|,
name|_func
parameter_list|,
name|_data
parameter_list|)
define|\
value|const struct sysinit UNIQ_NAME(sysuninit_##uniq) = {	\ 	.func = (_func),				\ 	.data = __DECONST(void *, _data)		\ };							\ SYSINIT_ENTRY(uniq##_entry, "sysuninit", (subs),	\     (order), "const struct sysuninit",			\     UNIQ_NAME_STR(sysuninit_##uniq), "SYSUNINIT")
end_define

begin_define
define|#
directive|define
name|MODULE_DEPEND
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|MODULE_VERSION
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NULL
value|((void *)0)
end_define

begin_define
define|#
directive|define
name|BUS_SPACE_BARRIER_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|BUS_SPACE_BARRIER_WRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|hz
value|1000
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b)) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|MTX_DEF
value|0
end_define

begin_define
define|#
directive|define
name|MTX_SPIN
value|0
end_define

begin_define
define|#
directive|define
name|MTX_RECURSE
value|0
end_define

begin_define
define|#
directive|define
name|SX_DUPOK
value|0
end_define

begin_define
define|#
directive|define
name|SX_NOWITNESS
value|0
end_define

begin_define
define|#
directive|define
name|WITNESS_WARN
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cold
value|0
end_define

begin_define
define|#
directive|define
name|BUS_PROBE_GENERIC
value|0
end_define

begin_define
define|#
directive|define
name|CALLOUT_RETURNUNLOCKED
value|0x1
end_define

begin_define
define|#
directive|define
name|va_list
value|__builtin_va_list
end_define

begin_define
define|#
directive|define
name|va_size
parameter_list|(
name|type
parameter_list|)
value|__builtin_va_size(type)
end_define

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|ap
parameter_list|,
name|last
parameter_list|)
value|__builtin_va_start(ap, last)
end_define

begin_define
define|#
directive|define
name|va_end
parameter_list|(
name|ap
parameter_list|)
value|__builtin_va_end(ap)
end_define

begin_define
define|#
directive|define
name|va_arg
parameter_list|(
name|ap
parameter_list|,
name|type
parameter_list|)
value|__builtin_va_arg((ap), type)
end_define

begin_define
define|#
directive|define
name|DEVICE_ATTACH
parameter_list|(
name|dev
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(((device_attach_t *)(device_get_method(dev, "device_attach")))(dev,## __VA_ARGS__))
end_define

begin_define
define|#
directive|define
name|DEVICE_DETACH
parameter_list|(
name|dev
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(((device_detach_t *)(device_get_method(dev, "device_detach")))(dev,## __VA_ARGS__))
end_define

begin_define
define|#
directive|define
name|DEVICE_PROBE
parameter_list|(
name|dev
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(((device_probe_t *)(device_get_method(dev, "device_probe")))(dev,## __VA_ARGS__))
end_define

begin_define
define|#
directive|define
name|DEVICE_RESUME
parameter_list|(
name|dev
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(((device_resume_t *)(device_get_method(dev, "device_resume")))(dev,## __VA_ARGS__))
end_define

begin_define
define|#
directive|define
name|DEVICE_SHUTDOWN
parameter_list|(
name|dev
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(((device_shutdown_t *)(device_get_method(dev, "device_shutdown")))(dev,## __VA_ARGS__))
end_define

begin_define
define|#
directive|define
name|DEVICE_SUSPEND
parameter_list|(
name|dev
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(((device_suspend_t *)(device_get_method(dev, "device_suspend")))(dev,## __VA_ARGS__))
end_define

begin_define
define|#
directive|define
name|USB_HANDLE_REQUEST
parameter_list|(
name|dev
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(((usb_handle_request_t *)(device_get_method(dev, "usb_handle_request")))(dev,## __VA_ARGS__))
end_define

begin_define
define|#
directive|define
name|USB_TAKE_CONTROLLER
parameter_list|(
name|dev
parameter_list|,
modifier|...
parameter_list|)
define|\
value|(((usb_take_controller_t *)(device_get_method(dev, "usb_take_controller")))(dev,## __VA_ARGS__))
end_define

begin_enum
enum|enum
block|{
name|SI_SUB_DUMMY
init|=
literal|0x0000000
block|,
name|SI_SUB_LOCK
init|=
literal|0x1B00000
block|,
name|SI_SUB_KLD
init|=
literal|0x2000000
block|,
name|SI_SUB_DRIVERS
init|=
literal|0x3100000
block|,
name|SI_SUB_PSEUDO
init|=
literal|0x7000000
block|,
name|SI_SUB_KICK_SCHEDULER
init|=
literal|0xa000000
block|,
name|SI_SUB_RUN_SCHEDULER
init|=
literal|0xfffffff
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|SI_ORDER_FIRST
init|=
literal|0x0000000
block|,
name|SI_ORDER_SECOND
init|=
literal|0x0000001
block|,
name|SI_ORDER_THIRD
init|=
literal|0x0000002
block|,
name|SI_ORDER_FOURTH
init|=
literal|0x0000003
block|,
name|SI_ORDER_MIDDLE
init|=
literal|0x1000000
block|,
name|SI_ORDER_ANY
init|=
literal|0xfffffff
comment|/* last */
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|malloc_type
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|usb_process
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|char
name|int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|short
name|int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|long
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|bus_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|bus_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u_long
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|bus_dmamap_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|bus_dma_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|bus_space_tag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
modifier|*
name|bus_space_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
modifier|*
name|caddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|__uintptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uintptr_t
typedef|;
end_typedef

begin_comment
comment|/* SYSINIT API */
end_comment

begin_include
include|#
directive|include
file|<sysinit.h>
end_include

begin_struct
struct|struct
name|sysinit
block|{
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* MUTEX API */
end_comment

begin_struct
struct|struct
name|mtx
block|{
name|int
name|owned
decl_stmt|;
name|struct
name|mtx
modifier|*
name|parent
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|mtx_assert
parameter_list|(
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_function_decl
name|void
name|mtx_init
parameter_list|(
name|struct
name|mtx
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mtx_lock
parameter_list|(
name|struct
name|mtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mtx_unlock
parameter_list|(
name|struct
name|mtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|mtx_lock_spin
parameter_list|(
name|x
parameter_list|)
value|mtx_lock(x)
end_define

begin_define
define|#
directive|define
name|mtx_unlock_spin
parameter_list|(
name|x
parameter_list|)
value|mtx_unlock(x)
end_define

begin_function_decl
name|int
name|mtx_owned
parameter_list|(
name|struct
name|mtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mtx_destroy
parameter_list|(
name|struct
name|mtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|Giant
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SX API */
end_comment

begin_struct
struct|struct
name|sx
block|{
name|int
name|owned
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sx_assert
parameter_list|(
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|sx_init
parameter_list|(
modifier|...
parameter_list|)
value|sx_init_flags(__VA_ARGS__, 0)
end_define

begin_function_decl
name|void
name|sx_init_flags
parameter_list|(
name|struct
name|sx
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sx_destroy
parameter_list|(
name|struct
name|sx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sx_xlock
parameter_list|(
name|struct
name|sx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sx_xunlock
parameter_list|(
name|struct
name|sx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sx_xlocked
parameter_list|(
name|struct
name|sx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* CONDVAR API */
end_comment

begin_struct
struct|struct
name|cv
block|{
name|int
name|sleeping
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|cv_init
parameter_list|(
name|struct
name|cv
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cv_destroy
parameter_list|(
name|struct
name|cv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cv_wait
parameter_list|(
name|struct
name|cv
modifier|*
parameter_list|,
name|struct
name|mtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cv_timedwait
parameter_list|(
name|struct
name|cv
modifier|*
parameter_list|,
name|struct
name|mtx
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cv_signal
parameter_list|(
name|struct
name|cv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cv_broadcast
parameter_list|(
name|struct
name|cv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* CALLOUT API */
end_comment

begin_typedef
typedef|typedef
name|void
name|callout_fn_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|volatile
name|int
name|ticks
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|callout
block|{
name|LIST_ENTRY
argument_list|(
argument|callout
argument_list|)
name|entry
expr_stmt|;
name|callout_fn_t
modifier|*
name|func
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|struct
name|mtx
modifier|*
name|mtx
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|int
name|timeout
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|callout_init_mtx
parameter_list|(
name|struct
name|callout
modifier|*
parameter_list|,
name|struct
name|mtx
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|callout_reset
parameter_list|(
name|struct
name|callout
modifier|*
parameter_list|,
name|int
parameter_list|,
name|callout_fn_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|callout_stop
parameter_list|(
name|struct
name|callout
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|callout_drain
parameter_list|(
name|struct
name|callout
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|callout_pending
parameter_list|(
name|struct
name|callout
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|callout_process
parameter_list|(
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DEVICE API */
end_comment

begin_struct_decl
struct_decl|struct
name|driver
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|devclass
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|device
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_data
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|driver
name|driver_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|devclass
modifier|*
name|devclass_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|device
modifier|*
name|device_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|driver_intr_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|driver_filter_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|FILTER_STRAY
value|0x01
end_define

begin_define
define|#
directive|define
name|FILTER_HANDLED
value|0x02
end_define

begin_define
define|#
directive|define
name|FILTER_SCHEDULE_THREAD
value|0x04
end_define

begin_typedef
typedef|typedef
name|int
name|device_attach_t
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|device_detach_t
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|device_resume_t
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|device_shutdown_t
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|device_probe_t
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|device_suspend_t
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|bus_child_location_str_t
parameter_list|(
name|device_t
name|parent
parameter_list|,
name|device_t
name|child
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|bus_child_pnpinfo_str_t
parameter_list|(
name|device_t
name|parent
parameter_list|,
name|device_t
name|child
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|bus_driver_added_t
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|driver_t
modifier|*
name|driver
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|device_method
block|{
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
name|void
modifier|*
specifier|const
name|func
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|device_method
name|device_method_t
typedef|;
end_typedef

begin_struct
struct|struct
name|device
block|{
name|TAILQ_HEAD
argument_list|(
argument|device_list
argument_list|,
argument|device
argument_list|)
name|dev_children
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|device
argument_list|)
name|dev_link
expr_stmt|;
name|struct
name|device
modifier|*
name|dev_parent
decl_stmt|;
specifier|const
name|struct
name|module_data
modifier|*
name|dev_module
decl_stmt|;
name|void
modifier|*
name|dev_sc
decl_stmt|;
name|void
modifier|*
name|dev_aux
decl_stmt|;
name|driver_filter_t
modifier|*
name|dev_irq_filter
decl_stmt|;
name|driver_intr_t
modifier|*
name|dev_irq_fn
decl_stmt|;
name|void
modifier|*
name|dev_irq_arg
decl_stmt|;
name|uint16_t
name|dev_unit
decl_stmt|;
name|char
name|dev_nameunit
index|[
literal|64
index|]
decl_stmt|;
name|char
name|dev_desc
index|[
literal|64
index|]
decl_stmt|;
name|uint8_t
name|dev_res_alloc
range|:
literal|1
decl_stmt|;
name|uint8_t
name|dev_quiet
range|:
literal|1
decl_stmt|;
name|uint8_t
name|dev_softc_set
range|:
literal|1
decl_stmt|;
name|uint8_t
name|dev_softc_alloc
range|:
literal|1
decl_stmt|;
name|uint8_t
name|dev_attached
range|:
literal|1
decl_stmt|;
name|uint8_t
name|dev_fixed_class
range|:
literal|1
decl_stmt|;
name|uint8_t
name|dev_unit_manual
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|devclass
block|{
name|device_t
name|dev_list
index|[
name|DEVCLASS_MAXUNIT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|driver
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|struct
name|device_method
modifier|*
name|methods
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|module_data
block|{
name|int
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|struct
name|module
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
modifier|*
name|arg
decl_stmt|;
specifier|const
name|char
modifier|*
name|bus_name
decl_stmt|;
specifier|const
name|char
modifier|*
name|mod_name
decl_stmt|;
specifier|const
name|char
modifier|*
name|long_name
decl_stmt|;
specifier|const
name|struct
name|driver
modifier|*
name|driver
decl_stmt|;
name|struct
name|devclass
modifier|*
modifier|*
name|devclass_pp
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|module_data
argument_list|)
name|entry
expr_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|device_t
name|device_get_parent
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|device_get_method
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|what
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|device_get_name
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|device_get_nameunit
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|device_printf
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|printf("%s: " fmt, device_get_nameunit(dev),## __VA_ARGS__)
end_define

begin_function_decl
name|device_t
name|device_add_child
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_quiet
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_set_interrupt
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|driver_filter_t
modifier|*
parameter_list|,
name|driver_intr_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_run_interrupts
parameter_list|(
name|device_t
name|parent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_set_ivars
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|ivars
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|device_get_ivars
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|device_get_desc
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_probe_and_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|device_get_softc
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_set_softc
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_delete_child
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_delete_children
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_is_attached
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_set_desc
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|device_set_desc_copy
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|device_get_unit
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|devclass_get_softc
parameter_list|(
name|devclass_t
name|dc
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devclass_get_maxunit
parameter_list|(
name|devclass_t
name|dc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|devclass_get_device
parameter_list|(
name|devclass_t
name|dc
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|devclass_t
name|devclass_find
parameter_list|(
specifier|const
name|char
modifier|*
name|classname
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|bus_get_dma_tag
parameter_list|(
modifier|...
parameter_list|)
value|(NULL)
end_define

begin_function_decl
name|int
name|bus_generic_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_generic_print_child
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_generic_driver_added
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|driver_t
modifier|*
name|driver
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* BUS SPACE API */
end_comment

begin_function_decl
name|void
name|bus_space_write_1
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint8_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_space_write_2
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint16_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_space_write_4
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint32_t
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|bus_space_read_1
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|bus_space_read_2
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bus_space_read_4
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_space_read_multi_1
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint8_t
modifier|*
name|datap
parameter_list|,
name|bus_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_space_read_multi_2
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint16_t
modifier|*
name|datap
parameter_list|,
name|bus_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_space_read_multi_4
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint32_t
modifier|*
name|datap
parameter_list|,
name|bus_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_space_write_multi_1
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint8_t
modifier|*
name|datap
parameter_list|,
name|bus_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_space_write_multi_2
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint16_t
modifier|*
name|datap
parameter_list|,
name|bus_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_space_write_multi_4
parameter_list|(
name|bus_space_tag_t
name|t
parameter_list|,
name|bus_space_handle_t
name|h
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint32_t
modifier|*
name|datap
parameter_list|,
name|bus_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_space_read_region_1
parameter_list|(
name|bus_space_tag_t
name|space
parameter_list|,
name|bus_space_handle_t
name|handle
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint8_t
modifier|*
name|datap
parameter_list|,
name|bus_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_space_write_region_1
parameter_list|(
name|bus_space_tag_t
name|space
parameter_list|,
name|bus_space_handle_t
name|handle
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint8_t
modifier|*
name|datap
parameter_list|,
name|bus_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_space_read_region_4
parameter_list|(
name|bus_space_tag_t
name|space
parameter_list|,
name|bus_space_handle_t
name|handle
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint32_t
modifier|*
name|datap
parameter_list|,
name|bus_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_space_write_region_4
parameter_list|(
name|bus_space_tag_t
name|space
parameter_list|,
name|bus_space_handle_t
name|handle
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint32_t
modifier|*
name|datap
parameter_list|,
name|bus_size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bus_space_barrier
parameter_list|(
name|bus_space_tag_t
name|space
parameter_list|,
name|bus_space_handle_t
name|handle
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|bus_size_t
name|length
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|module_register
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* LIB-C */
end_comment

begin_function_decl
name|void
modifier|*
name|memset
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memcpy
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|snprintf
parameter_list|(
name|char
modifier|*
specifier|restrict
name|str
parameter_list|,
name|size_t
name|size
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MALLOC API */
end_comment

begin_define
define|#
directive|define
name|malloc
parameter_list|(
name|s
parameter_list|,
name|x
parameter_list|,
name|f
parameter_list|)
value|usb_malloc(s)
end_define

begin_function_decl
name|void
modifier|*
name|usb_malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|free
parameter_list|(
name|p
parameter_list|,
name|x
parameter_list|)
value|usb_free(p)
end_define

begin_function_decl
name|void
name|usb_free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|strdup
parameter_list|(
name|p
parameter_list|,
name|x
parameter_list|)
value|usb_strdup(p)
end_define

begin_function_decl
name|char
modifier|*
name|usb_strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ENDIANNESS */
end_comment

begin_comment
comment|/* Assume little endian */
end_comment

begin_define
define|#
directive|define
name|htole64
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x))
end_define

begin_define
define|#
directive|define
name|le64toh
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x))
end_define

begin_define
define|#
directive|define
name|htole32
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|le32toh
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|htole16
parameter_list|(
name|x
parameter_list|)
value|((uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|le16toh
parameter_list|(
name|x
parameter_list|)
value|((uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|be32toh
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|htobe32
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)(x))
end_define

begin_comment
comment|/* USB */
end_comment

begin_typedef
typedef|typedef
name|int
name|usb_handle_request_t
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|void
modifier|*
name|req
parameter_list|,
name|void
modifier|*
modifier|*
name|pptr
parameter_list|,
name|uint16_t
modifier|*
name|plen
parameter_list|,
name|uint16_t
name|offset
parameter_list|,
name|uint8_t
modifier|*
name|pstate
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|usb_take_controller_t
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|usb_idle
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_uninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set some defaults */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USB_POOL_SIZE
end_ifndef

begin_define
define|#
directive|define
name|USB_POOL_SIZE
value|(1024*1024)
end_define

begin_comment
comment|/* 1 MByte */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|pause
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DELAY
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* OTHER */
end_comment

begin_struct
struct|struct
name|selinfo
block|{ }
struct|;
end_struct

begin_comment
comment|/* SYSTEM STARTUP API */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|void
modifier|*
name|sysinit_data
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|void
modifier|*
name|sysuninit_data
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_KERNEL_H_ */
end_comment

end_unit

