begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * hvm/save.h  *  * Structure definitions for HVM state that is held by Xen and must  * be saved along with the domain's memory and device-model state.  *   * Copyright (c) 2007 XenSource Ltd.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_HVM_SAVE_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_HVM_SAVE_H__
end_define

begin_comment
comment|/*  * Structures in this header *must* have the same layout in 32bit   * and 64bit environments: this means that all fields must be explicitly   * sized types and aligned to their sizes, and the structs must be   * a multiple of eight bytes long.  *  * Only the state necessary for saving and restoring (i.e. fields   * that are analogous to actual hardware state) should go in this file.   * Internal mechanisms should be kept in Xen-private headers.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Anonymous structs/unions are a GNU extension."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * Each entry is preceded by a descriptor giving its type and length  */
end_comment

begin_struct
struct|struct
name|hvm_save_descriptor
block|{
name|uint16_t
name|typecode
decl_stmt|;
comment|/* Used to demux the various types below */
name|uint16_t
name|instance
decl_stmt|;
comment|/* Further demux within a type */
name|uint32_t
name|length
decl_stmt|;
comment|/* In bytes, *not* including this descriptor */
block|}
struct|;
end_struct

begin_comment
comment|/*   * Each entry has a datatype associated with it: for example, the CPU state   * is saved as a HVM_SAVE_TYPE(CPU), which has HVM_SAVE_LENGTH(CPU),   * and is identified by a descriptor with typecode HVM_SAVE_CODE(CPU).  * DECLARE_HVM_SAVE_TYPE binds these things together with some type-system  * ugliness.  */
end_comment

begin_define
define|#
directive|define
name|DECLARE_HVM_SAVE_TYPE
parameter_list|(
name|_x
parameter_list|,
name|_code
parameter_list|,
name|_type
parameter_list|)
define|\
value|struct __HVM_SAVE_TYPE_##_x { _type t; char c[_code]; }
end_define

begin_define
define|#
directive|define
name|HVM_SAVE_TYPE
parameter_list|(
name|_x
parameter_list|)
value|typeof (((struct __HVM_SAVE_TYPE_##_x *)(0))->t)
end_define

begin_define
define|#
directive|define
name|HVM_SAVE_LENGTH
parameter_list|(
name|_x
parameter_list|)
value|(sizeof (HVM_SAVE_TYPE(_x)))
end_define

begin_define
define|#
directive|define
name|HVM_SAVE_CODE
parameter_list|(
name|_x
parameter_list|)
value|(sizeof (((struct __HVM_SAVE_TYPE_##_x *)(0))->c))
end_define

begin_comment
comment|/*   * The series of save records is teminated by a zero-type, zero-length   * descriptor.  */
end_comment

begin_struct
struct|struct
name|hvm_save_end
block|{}
struct|;
end_struct

begin_expr_stmt
name|DECLARE_HVM_SAVE_TYPE
argument_list|(
name|END
argument_list|,
literal|0
argument_list|,
expr|struct
name|hvm_save_end
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"../arch-x86/hvm/save.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"../arch-ia64/hvm/save.h"
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
literal|"unsupported architecture"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_HVM_SAVE_H__ */
end_comment

end_unit

