begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_HVM_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_HVM_H__
end_define

begin_include
include|#
directive|include
file|<xen/xen-os.h>
end_include

begin_include
include|#
directive|include
file|<xen/hypervisor.h>
end_include

begin_include
include|#
directive|include
file|<xen/interface/hvm/params.h>
end_include

begin_comment
comment|/**  * \brief Wrapper function to obtain a HVM parameter value.  *  * \param index	HVM parameter index; see<xen/interface/hvm/params.h>.  *   * \returns	0 on failure; the value of the parameter otherwise.  */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|hvm_get_parameter
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|struct
name|xen_hvm_param
name|xhv
decl_stmt|;
name|int
name|error
decl_stmt|;
name|xhv
operator|.
name|domid
operator|=
name|DOMID_SELF
expr_stmt|;
name|xhv
operator|.
name|index
operator|=
name|index
expr_stmt|;
name|error
operator|=
name|HYPERVISOR_hvm_op
argument_list|(
name|HVMOP_get_param
argument_list|,
operator|&
name|xhv
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|printf
argument_list|(
literal|"%s: error %d trying to get %d\n"
argument_list|,
name|__func__
argument_list|,
name|error
argument_list|,
name|index
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
name|xhv
operator|.
name|value
operator|)
return|;
block|}
end_function

begin_comment
comment|/** The callback method types for Hypervisor event delivery to our domain. */
end_comment

begin_enum
enum|enum
block|{
name|HVM_CB_TYPE_GSI
block|,
name|HVM_CB_TYPE_PCI_INTX
block|,
name|HVM_CB_TYPE_VECTOR
block|,
name|HVM_CB_TYPE_MASK
init|=
literal|0xFF
block|,
name|HVM_CB_TYPE_SHIFT
init|=
literal|56
block|}
enum|;
end_enum

begin_comment
comment|/** Format for specifying a GSI type callback. */
end_comment

begin_enum
enum|enum
block|{
name|HVM_CB_GSI_GSI_MASK
init|=
literal|0xFFFFFFFF
block|,
name|HVM_CB_GSI_GSI_SHIFT
init|=
literal|0
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|HVM_CALLBACK_GSI
parameter_list|(
name|gsi
parameter_list|)
define|\
value|(((uint64_t)HVM_CB_TYPE_GSI<< HVM_CB_TYPE_SHIFT) \    | ((gsi)& HVM_CB_GSI_GSI_MASK)<< HVM_CB_GSI_GSI_SHIFT)
end_define

begin_comment
comment|/** Format for specifying a virtual PCI interrupt line GSI style callback. */
end_comment

begin_enum
enum|enum
block|{
name|HVM_CB_PCI_INTX_INTPIN_MASK
init|=
literal|0x3
block|,
name|HVM_CB_PCI_INTX_INTPIN_SHIFT
init|=
literal|0
block|,
name|HVM_CB_PCI_INTX_SLOT_MASK
init|=
literal|0x1F
block|,
name|HVM_CB_PCI_INTX_SLOT_SHIFT
init|=
literal|11
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|HVM_CALLBACK_PCI_INTX
parameter_list|(
name|slot
parameter_list|,
name|pin
parameter_list|)
define|\
value|(((uint64_t)HVM_CB_TYPE_PCI_INTX<< HVM_CB_TYPE_SHIFT) \    | (((slot)& HVM_CB_PCI_INTX_SLOT_MASK)<< HVM_CB_PCI_INTX_SLOT_SHIFT) \    | (((pin)& HVM_CB_PCI_INTX_INTPIN_MASK)<< HVM_CB_PCI_INTX_INTPIN_SHIFT))
end_define

begin_comment
comment|/** Format for specifying a direct IDT vector injection style callback. */
end_comment

begin_enum
enum|enum
block|{
name|HVM_CB_VECTOR_VECTOR_MASK
init|=
literal|0xFFFFFFFF
block|,
name|HVM_CB_VECTOR_VECTOR_SHIFT
init|=
literal|0
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|HVM_CALLBACK_VECTOR
parameter_list|(
name|vector
parameter_list|)
define|\
value|(((uint64_t)HVM_CB_TYPE_VECTOR<< HVM_CB_TYPE_SHIFT) \    | (((vector)& HVM_CB_GSI_GSI_MASK)<< HVM_CB_GSI_GSI_SHIFT))
end_define

begin_function_decl
name|void
name|xen_hvm_set_callback
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xen_hvm_suspend
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xen_hvm_resume
parameter_list|(
name|bool
name|suspend_cancelled
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_HVM_H__ */
end_comment

end_unit

