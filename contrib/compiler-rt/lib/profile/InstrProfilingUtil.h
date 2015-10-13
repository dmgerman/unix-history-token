begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===- InstrProfilingUtil.h - Support library for PGO instrumentation -----===*\ |* |*                     The LLVM Compiler Infrastructure |* |* This file is distributed under the University of Illinois Open Source |* License. See LICENSE.TXT for details. |* \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROFILE_INSTRPROFILINGUTIL_H
end_ifndef

begin_define
define|#
directive|define
name|PROFILE_INSTRPROFILINGUTIL_H
end_define

begin_comment
comment|/*! \brief Create a directory tree. */
end_comment

begin_function_decl
name|void
name|__llvm_profile_recursive_mkdir
parameter_list|(
name|char
modifier|*
name|Pathname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROFILE_INSTRPROFILINGUTIL_H */
end_comment

end_unit

