begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// script.h -- handle linker scripts for gold   -*- C++ -*-
end_comment

begin_comment
comment|// We implement a subset of the original GNU ld linker script language
end_comment

begin_comment
comment|// for compatibility.  The goal is not to implement the entire
end_comment

begin_comment
comment|// language.  It is merely to implement enough to handle common uses.
end_comment

begin_comment
comment|// In particular we need to handle /usr/lib/libc.so on a typical
end_comment

begin_comment
comment|// GNU/Linux system, and we want to handle linker scripts used by the
end_comment

begin_comment
comment|// Linux kernel build.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_SCRIPT_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_SCRIPT_H
end_define

begin_decl_stmt
name|namespace
name|gold
block|{
name|class
name|General_options
decl_stmt|;
name|class
name|Symbol_table
decl_stmt|;
name|class
name|Layout
decl_stmt|;
name|class
name|Input_objects
decl_stmt|;
name|class
name|Input_group
decl_stmt|;
name|class
name|Input_file
decl_stmt|;
name|class
name|Task_token
decl_stmt|;
comment|// FILE was found as an argument on the command line, but was not
comment|// recognized as an ELF file.  Try to read it as a script.  We've
comment|// already read BYTES of data into P.  Return true if the file was
comment|// handled.  This has to handle /usr/lib/libc.so on a GNU/Linux
comment|// system.
name|bool
name|read_input_script
parameter_list|(
name|Workqueue
modifier|*
parameter_list|,
specifier|const
name|General_options
modifier|&
parameter_list|,
name|Symbol_table
modifier|*
parameter_list|,
name|Layout
modifier|*
parameter_list|,
specifier|const
name|Dirsearch
modifier|&
parameter_list|,
name|Input_objects
modifier|*
parameter_list|,
name|Input_group
modifier|*
parameter_list|,
specifier|const
name|Input_argument
modifier|*
parameter_list|,
name|Input_file
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|p
parameter_list|,
name|off_t
name|bytes
parameter_list|,
name|Task_token
modifier|*
name|this_blocker
parameter_list|,
name|Task_token
modifier|*
name|next_blocker
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace gold.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_SCRIPT_H)
end_comment

end_unit

