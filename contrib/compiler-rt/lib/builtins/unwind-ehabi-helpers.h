begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- arm-ehabi-helpers.h - Supplementary ARM EHABI declarations --------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===--------------------------------------------------------------------=== */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNWIND_EHABI_HELPERS_H
end_ifndef

begin_define
define|#
directive|define
name|UNWIND_EHABI_HELPERS_H
end_define

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|/* NOTE: see reasoning for this inclusion below */
end_comment

begin_include
include|#
directive|include
file|<unwind.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__ARM_EABI_UNWINDER__
argument_list|)
end_if

begin_comment
comment|/*  * NOTE: _URC_OK, _URC_FAILURE must be present as preprocessor tokens.  This  * allows for a substitution of a constant which can be cast into the  * appropriate enumerated type.  This header is expected to always be included  * AFTER unwind.h (which is why it is forcefully included above).  This ensures  * that we do not overwrite the token for the enumeration.  Subsequent uses of  * the token would be clean to rewrite with constant values.  *  * The typedef redeclaration should be safe.  Due to the protection granted to  * us by the `__ARM_EABI_UNWINDER__` above, we are guaranteed that we are in a  * header not vended by gcc.  The HP unwinder (being an itanium unwinder) does  * not support EHABI, and the GNU unwinder, derived from the HP unwinder, also  * does not support EHABI as of the introduction of this header.  As such, we  * are fairly certain that we are in the LLVM case.  Here, _Unwind_State is a  * typedef, and so we can get away with a redeclaration.  *  * Guarded redefinitions of the needed unwind state prevent the redefinition of  * those states.  */
end_comment

begin_define
define|#
directive|define
name|_URC_OK
value|0
end_define

begin_define
define|#
directive|define
name|_URC_FAILURE
value|9
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|_Unwind_State
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_US_UNWIND_FRAME_STARTING
argument_list|)
end_if

begin_define
define|#
directive|define
name|_US_UNWIND_FRAME_STARTING
value|((_Unwind_State)1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_US_ACTION_MASK
argument_list|)
end_if

begin_define
define|#
directive|define
name|_US_ACTION_MASK
value|((_Unwind_State)3)
end_define

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

end_unit

