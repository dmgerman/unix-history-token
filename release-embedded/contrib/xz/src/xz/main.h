begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       main.h
end_comment

begin_comment
comment|/// \brief      Miscellaneous declarations
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|/// Possible exit status values. These are the same as used by gzip and bzip2.
end_comment

begin_enum
enum|enum
name|exit_status_type
block|{
name|E_SUCCESS
init|=
literal|0
block|,
name|E_ERROR
init|=
literal|1
block|,
name|E_WARNING
init|=
literal|2
block|, }
enum|;
end_enum

begin_comment
comment|/// Sets the exit status after a warning or error has occurred. If new_status
end_comment

begin_comment
comment|/// is E_WARNING and the old exit status was already E_ERROR, the exit
end_comment

begin_comment
comment|/// status is not changed.
end_comment

begin_function_decl
specifier|extern
name|void
name|set_exit_status
parameter_list|(
name|enum
name|exit_status_type
name|new_status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Use E_SUCCESS instead of E_WARNING if something worth a warning occurs
end_comment

begin_comment
comment|/// but nothing worth an error has occurred. This is called when --no-warn
end_comment

begin_comment
comment|/// is specified.
end_comment

begin_function_decl
specifier|extern
name|void
name|set_exit_no_warn
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

