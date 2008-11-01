begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * callback.h  *  * Register guest OS callbacks with Xen.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2006, Ian Campbell  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_CALLBACK_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_CALLBACK_H__
end_define

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_comment
comment|/*  * Prototype for this hypercall is:  *   long callback_op(int cmd, void *extra_args)  * @cmd        == CALLBACKOP_??? (callback operation).  * @extra_args == Operation-specific extra arguments (NULL if none).  */
end_comment

begin_comment
comment|/* ia64, x86: Callback for event delivery. */
end_comment

begin_define
define|#
directive|define
name|CALLBACKTYPE_event
value|0
end_define

begin_comment
comment|/* x86: Failsafe callback when guest state cannot be restored by Xen. */
end_comment

begin_define
define|#
directive|define
name|CALLBACKTYPE_failsafe
value|1
end_define

begin_comment
comment|/* x86/64 hypervisor: Syscall by 64-bit guest app ('64-on-64-on-64'). */
end_comment

begin_define
define|#
directive|define
name|CALLBACKTYPE_syscall
value|2
end_define

begin_comment
comment|/*  * x86/32 hypervisor: Only available on x86/32 when supervisor_mode_kernel  *     feature is enabled. Do not use this callback type in new code.  */
end_comment

begin_define
define|#
directive|define
name|CALLBACKTYPE_sysenter_deprecated
value|3
end_define

begin_comment
comment|/* x86: Callback for NMI delivery. */
end_comment

begin_define
define|#
directive|define
name|CALLBACKTYPE_nmi
value|4
end_define

begin_comment
comment|/*  * x86: sysenter is only available as follows:  * - 32-bit hypervisor: with the supervisor_mode_kernel feature enabled  * - 64-bit hypervisor: 32-bit guest applications on Intel CPUs  *                      ('32-on-32-on-64', '32-on-64-on-64')  *                      [nb. also 64-bit guest applications on Intel CPUs  *                           ('64-on-64-on-64'), but syscall is preferred]  */
end_comment

begin_define
define|#
directive|define
name|CALLBACKTYPE_sysenter
value|5
end_define

begin_comment
comment|/*  * x86/64 hypervisor: Syscall by 32-bit guest app on AMD CPUs  *                    ('32-on-32-on-64', '32-on-64-on-64')  */
end_comment

begin_define
define|#
directive|define
name|CALLBACKTYPE_syscall32
value|7
end_define

begin_comment
comment|/*  * Disable event deliver during callback? This flag is ignored for event and  * NMI callbacks: event delivery is unconditionally disabled.  */
end_comment

begin_define
define|#
directive|define
name|_CALLBACKF_mask_events
value|0
end_define

begin_define
define|#
directive|define
name|CALLBACKF_mask_events
value|(1U<< _CALLBACKF_mask_events)
end_define

begin_comment
comment|/*  * Register a callback.  */
end_comment

begin_define
define|#
directive|define
name|CALLBACKOP_register
value|0
end_define

begin_struct
struct|struct
name|callback_register
block|{
name|uint16_t
name|type
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
name|xen_callback_t
name|address
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|callback_register
name|callback_register_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|callback_register_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Unregister a callback.  *  * Not all callbacks can be unregistered. -EINVAL will be returned if  * you attempt to unregister such a callback.  */
end_comment

begin_define
define|#
directive|define
name|CALLBACKOP_unregister
value|1
end_define

begin_struct
struct|struct
name|callback_unregister
block|{
name|uint16_t
name|type
decl_stmt|;
name|uint16_t
name|_unused
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|callback_unregister
name|callback_unregister_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|callback_unregister_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|__XEN_INTERFACE_VERSION__
operator|<
literal|0x00030207
end_if

begin_undef
undef|#
directive|undef
name|CALLBACKTYPE_sysenter
end_undef

begin_define
define|#
directive|define
name|CALLBACKTYPE_sysenter
value|CALLBACKTYPE_sysenter_deprecated
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_CALLBACK_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

