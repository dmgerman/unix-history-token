begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===---- unwind.h - Stack unwinding ----------------------------------------===  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  * THE SOFTWARE.  *  *===-----------------------------------------------------------------------===  */
end_comment

begin_comment
comment|/* See "Data Definitions for libgcc_s" in the Linux Standard Base.*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CLANG_UNWIND_H
end_ifndef

begin_define
define|#
directive|define
name|__CLANG_UNWIND_H
end_define

begin_if
if|#
directive|if
name|__has_include_next
argument_list|(
operator|<
name|unwind
operator|.
name|h
operator|>
argument_list|)
end_if

begin_comment
comment|/* Darwin and libunwind provide an unwind.h. If that's available, use  * it. libunwind wraps some of its definitions in #ifdef _GNU_SOURCE,  * so define that around the include.*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_SHOULD_UNDEFINE_GNU_SOURCE
end_define

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// libunwind's unwind.h reflects the current visibility.  However, Mozilla
end_comment

begin_comment
comment|// builds with -fvisibility=hidden and relies on gcc's unwind.h to reset the
end_comment

begin_comment
comment|// visibility to default and export its contents.  gcc also allows users to
end_comment

begin_comment
comment|// override its override by #defining HIDE_EXPORTS (but note, this only obeys
end_comment

begin_comment
comment|// the user's -fvisibility setting; it doesn't hide any exports on its own).  We
end_comment

begin_comment
comment|// imitate gcc's header here:
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HIDE_EXPORTS
end_ifdef

begin_empty
empty|#  include_next<unwind.h>
end_empty

begin_else
else|#
directive|else
end_else

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|push
name|(
name|default
name|)
end_pragma

begin_empty
empty|#  include_next<unwind.h>
end_empty

begin_pragma
pragma|#
directive|pragma
name|GCC
name|visibility
name|pop
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_SHOULD_UNDEFINE_GNU_SOURCE
end_ifdef

begin_undef
undef|#
directive|undef
name|_GNU_SOURCE
end_undef

begin_undef
undef|#
directive|undef
name|_SHOULD_UNDEFINE_GNU_SOURCE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* It is a bit strange for a header to play with the visibility of the    symbols it declares, but this matches gcc's behavior and some programs    depend on it */
ifndef|#
directive|ifndef
name|HIDE_EXPORTS
pragma|#
directive|pragma
name|GCC
name|visibility
name|push
name|(
name|default
name|)
endif|#
directive|endif
struct_decl|struct
name|_Unwind_Context
struct_decl|;
typedef|typedef
enum|enum
block|{
name|_URC_NO_REASON
init|=
literal|0
block|,
name|_URC_FOREIGN_EXCEPTION_CAUGHT
init|=
literal|1
block|,
name|_URC_FATAL_PHASE2_ERROR
init|=
literal|2
block|,
name|_URC_FATAL_PHASE1_ERROR
init|=
literal|3
block|,
name|_URC_NORMAL_STOP
init|=
literal|4
block|,
name|_URC_END_OF_STACK
init|=
literal|5
block|,
name|_URC_HANDLER_FOUND
init|=
literal|6
block|,
name|_URC_INSTALL_CONTEXT
init|=
literal|7
block|,
name|_URC_CONTINUE_UNWIND
init|=
literal|8
block|}
name|_Unwind_Reason_Code
typedef|;
ifdef|#
directive|ifdef
name|__arm__
typedef|typedef
enum|enum
block|{
name|_UVRSC_CORE
init|=
literal|0
block|,
comment|/* integer register */
name|_UVRSC_VFP
init|=
literal|1
block|,
comment|/* vfp */
name|_UVRSC_WMMXD
init|=
literal|3
block|,
comment|/* Intel WMMX data register */
name|_UVRSC_WMMXC
init|=
literal|4
comment|/* Intel WMMX control register */
block|}
name|_Unwind_VRS_RegClass
typedef|;
typedef|typedef
enum|enum
block|{
name|_UVRSD_UINT32
init|=
literal|0
block|,
name|_UVRSD_VFPX
init|=
literal|1
block|,
name|_UVRSD_UINT64
init|=
literal|3
block|,
name|_UVRSD_FLOAT
init|=
literal|4
block|,
name|_UVRSD_DOUBLE
init|=
literal|5
block|}
name|_Unwind_VRS_DataRepresentation
typedef|;
typedef|typedef
enum|enum
block|{
name|_UVRSR_OK
init|=
literal|0
block|,
name|_UVRSR_NOT_IMPLEMENTED
init|=
literal|1
block|,
name|_UVRSR_FAILED
init|=
literal|2
block|}
name|_Unwind_VRS_Result
typedef|;
name|_Unwind_VRS_Result
name|_Unwind_VRS_Get
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|__context
parameter_list|,
name|_Unwind_VRS_RegClass
name|__regclass
parameter_list|,
name|uint32_t
name|__regno
parameter_list|,
name|_Unwind_VRS_DataRepresentation
name|__representation
parameter_list|,
name|void
modifier|*
name|__valuep
parameter_list|)
function_decl|;
else|#
directive|else
name|uintptr_t
name|_Unwind_GetIP
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
name|__context
parameter_list|)
function_decl|;
endif|#
directive|endif
typedef|typedef
name|_Unwind_Reason_Code
function_decl|(
modifier|*
name|_Unwind_Trace_Fn
function_decl|)
parameter_list|(
name|struct
name|_Unwind_Context
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|_Unwind_Reason_Code
name|_Unwind_Backtrace
parameter_list|(
name|_Unwind_Trace_Fn
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|HIDE_EXPORTS
pragma|#
directive|pragma
name|GCC
name|visibility
name|pop
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CLANG_UNWIND_H */
end_comment

end_unit

