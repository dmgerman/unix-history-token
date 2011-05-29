begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       suffix.h
end_comment

begin_comment
comment|/// \brief      Checks filename suffix and creates the destination filename
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
comment|/// \brief      Get the name of the destination file
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Depending on the global variable opt_mode, this tries to find a matching
end_comment

begin_comment
comment|/// counterpart for src_name. If the name can be constructed, it is allocated
end_comment

begin_comment
comment|/// and returned (caller must free it). On error, a message is printed and
end_comment

begin_comment
comment|/// NULL is returned.
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|suffix_get_dest_name
parameter_list|(
specifier|const
name|char
modifier|*
name|src_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Set a custom filename suffix
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function calls xstrdup() for the given suffix, thus the caller
end_comment

begin_comment
comment|/// doesn't need to keep the memory allocated. There can be only one custom
end_comment

begin_comment
comment|/// suffix, thus if this is called multiple times, the old suffixes are freed
end_comment

begin_comment
comment|/// and forgotten.
end_comment

begin_function_decl
specifier|extern
name|void
name|suffix_set
parameter_list|(
specifier|const
name|char
modifier|*
name|suffix
parameter_list|)
function_decl|;
end_function_decl

end_unit

