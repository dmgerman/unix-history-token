begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * nmi.h  *   * NMI callback registration and reason codes.  *   * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Copyright (c) 2005, Keir Fraser<keir@xensource.com>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_NMI_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_NMI_H__
end_define

begin_comment
comment|/*  * NMI reason codes:  * Currently these are x86-specific, stored in arch_shared_info.nmi_reason.  */
end_comment

begin_comment
comment|/* I/O-check error reported via ISA port 0x61, bit 6. */
end_comment

begin_define
define|#
directive|define
name|_XEN_NMIREASON_io_error
value|0
end_define

begin_define
define|#
directive|define
name|XEN_NMIREASON_io_error
value|(1UL<< _XEN_NMIREASON_io_error)
end_define

begin_comment
comment|/* Parity error reported via ISA port 0x61, bit 7. */
end_comment

begin_define
define|#
directive|define
name|_XEN_NMIREASON_parity_error
value|1
end_define

begin_define
define|#
directive|define
name|XEN_NMIREASON_parity_error
value|(1UL<< _XEN_NMIREASON_parity_error)
end_define

begin_comment
comment|/* Unknown hardware-generated NMI. */
end_comment

begin_define
define|#
directive|define
name|_XEN_NMIREASON_unknown
value|2
end_define

begin_define
define|#
directive|define
name|XEN_NMIREASON_unknown
value|(1UL<< _XEN_NMIREASON_unknown)
end_define

begin_comment
comment|/*  * long nmi_op(unsigned int cmd, void *arg)  * NB. All ops return zero on success, else a negative error code.  */
end_comment

begin_comment
comment|/*  * Register NMI callback for this (calling) VCPU. Currently this only makes  * sense for domain 0, vcpu 0. All other callers will be returned EINVAL.  * arg == pointer to xennmi_callback structure.  */
end_comment

begin_define
define|#
directive|define
name|XENNMI_register_callback
value|0
end_define

begin_struct
struct|struct
name|xennmi_callback
block|{
name|unsigned
name|long
name|handler_address
decl_stmt|;
name|unsigned
name|long
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|xennmi_callback
name|xennmi_callback_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xennmi_callback_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Deregister NMI callback for this (calling) VCPU.  * arg == NULL.  */
end_comment

begin_define
define|#
directive|define
name|XENNMI_unregister_callback
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_NMI_H__ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

