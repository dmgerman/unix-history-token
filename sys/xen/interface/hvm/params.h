begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_HVM_PARAMS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_HVM_PARAMS_H__
end_define

begin_include
include|#
directive|include
file|"hvm_op.h"
end_include

begin_comment
comment|/*  * Parameter space for HVMOP_{set,get}_param.  */
end_comment

begin_comment
comment|/*  * How should CPU0 event-channel notifications be delivered?  * val[63:56] == 0: val[55:0] is a delivery GSI (Global System Interrupt).  * val[63:56] == 1: val[55:0] is a delivery PCI INTx line, as follows:  *                  Domain = val[47:32], Bus  = val[31:16],  *                  DevFn  = val[15: 8], IntX = val[ 1: 0]  * If val == 0 then CPU0 event-channel notifications are not delivered.  */
end_comment

begin_define
define|#
directive|define
name|HVM_PARAM_CALLBACK_IRQ
value|0
end_define

begin_comment
comment|/*  * These are not used by Xen. They are here for convenience of HVM-guest  * xenbus implementations.  */
end_comment

begin_define
define|#
directive|define
name|HVM_PARAM_STORE_PFN
value|1
end_define

begin_define
define|#
directive|define
name|HVM_PARAM_STORE_EVTCHN
value|2
end_define

begin_define
define|#
directive|define
name|HVM_PARAM_PAE_ENABLED
value|4
end_define

begin_define
define|#
directive|define
name|HVM_PARAM_IOREQ_PFN
value|5
end_define

begin_define
define|#
directive|define
name|HVM_PARAM_BUFIOREQ_PFN
value|6
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ia64__
end_ifdef

begin_define
define|#
directive|define
name|HVM_PARAM_NVRAM_FD
value|7
end_define

begin_define
define|#
directive|define
name|HVM_NR_PARAMS
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HVM_NR_PARAMS
value|7
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
comment|/* __XEN_PUBLIC_HVM_PARAMS_H__ */
end_comment

end_unit

