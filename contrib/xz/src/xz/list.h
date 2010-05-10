begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       list.h
end_comment

begin_comment
comment|/// \brief      List information about .xz files
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
comment|/// \brief      List information about the given .xz file
end_comment

begin_function_decl
specifier|extern
name|void
name|list_file
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Show the totals after all files have been listed
end_comment

begin_function_decl
specifier|extern
name|void
name|list_totals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

