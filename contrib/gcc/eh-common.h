begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* EH stuff    Copyright (C) 1997, 1998 Free Software Foundation, Inc.  This file is part of GNU CC.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file contains the structures required for the language    independant exception handling model. Both the static compiler and    the runtime library share this file. */
end_comment

begin_comment
comment|/* The runtime flag flag_new_exceptions is used to determine whether the     compiler supports the new runtime typechecking mechanism or not. Under    the new model, runtime info is contained in the exception table, and    the __throw() library routine determines which handler to call based    on the results of a call to a matching function provided by the expcetion    thrower.  Otherwise the old scheme of calling any handler which matches    an exception range is used, and the handler is responsible for all    checking of runtime conditions. If the handler wasn't suppose to    get the exception, it performs a re-throw. */
end_comment

begin_comment
comment|/* The handler_label field MUST be the first field in this structure. The     __throw()  library routine expects uses __eh_stub() from except.c, which    simply dereferences the context pointer to get the handler.    The routine get_dynamic_handler_chain() also has a dependancy on    the location of 'dynamic_handler_chain'. If its location is changed,     that routine must be modified as well. */
end_comment

begin_struct
struct|struct
name|eh_context
block|{
name|void
modifier|*
name|handler_label
decl_stmt|;
name|void
modifier|*
modifier|*
name|dynamic_handler_chain
decl_stmt|;
comment|/* This is language dependent part of the eh context. */
name|void
modifier|*
name|info
decl_stmt|;
comment|/* This is used to remember where we threw for re-throws */
name|void
modifier|*
name|table_index
decl_stmt|;
comment|/* address of exception table entry to rethrow from */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|EH_TABLE_LOOKUP
end_ifndef

begin_typedef
typedef|typedef
struct|struct
name|old_exception_table
block|{
name|void
modifier|*
name|start_region
decl_stmt|;
name|void
modifier|*
name|end_region
decl_stmt|;
name|void
modifier|*
name|exception_handler
decl_stmt|;
block|}
name|old_exception_table
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|exception_table
block|{
name|void
modifier|*
name|start_region
decl_stmt|;
name|void
modifier|*
name|end_region
decl_stmt|;
name|void
modifier|*
name|exception_handler
decl_stmt|;
name|void
modifier|*
name|match_info
decl_stmt|;
comment|/* runtime type info */
block|}
name|exception_table
typedef|;
end_typedef

begin_comment
comment|/* The language identifying portion of an exception table */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|exception_lang_info
block|{
name|short
name|language
decl_stmt|;
name|short
name|version
decl_stmt|;
block|}
name|exception_lang_info
typedef|;
end_typedef

begin_comment
comment|/* This value in the first field of the exception descriptor     identifies the descriptor as the new model format. This value would never    be present in this location under the old model */
end_comment

begin_define
define|#
directive|define
name|NEW_EH_RUNTIME
value|((void *) -2)
end_define

begin_comment
comment|/* Each function has an exception_descriptor which contains the    language info, and a table of exception ranges and handlers */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|exception_descriptor
block|{
name|void
modifier|*
name|runtime_id_field
decl_stmt|;
name|exception_lang_info
name|lang
decl_stmt|;
name|exception_table
name|table
index|[
literal|1
index|]
decl_stmt|;
block|}
name|exception_descriptor
typedef|;
end_typedef

begin_comment
comment|/* A pointer to a matching function is initialized at runtime by the     specific language if run-time exceptions are supported.     The function takes 3 parameters     1 - runtime exception that has been thrown info. (__eh_info *)     2 - Match info pointer from the region being considered (void *)     3 - exception table region is in (exception descriptor *) */
end_comment

begin_typedef
typedef|typedef
name|void
operator|*
operator|(
operator|*
name|__eh_matcher
operator|)
name|PROTO
argument_list|(
operator|(
name|void
operator|*
operator|,
name|void
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* This value is to be checked as a 'match all' case in the runtime field. */
end_comment

begin_define
define|#
directive|define
name|CATCH_ALL_TYPE
value|((void *) -1)
end_define

begin_comment
comment|/* This is the runtime exception information. This forms the minimum required    information for an exception info pointer in an eh_context structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__eh_info
block|{
name|__eh_matcher
name|match_function
decl_stmt|;
name|short
name|language
decl_stmt|;
name|short
name|version
decl_stmt|;
block|}
name|__eh_info
typedef|;
end_typedef

begin_comment
comment|/* Convienient language codes for ID the originating language. Similar    to the codes in dwarf2.h. */
end_comment

begin_enum
enum|enum
name|exception_source_language
block|{
name|EH_LANG_C89
init|=
literal|0x0001
block|,
name|EH_LANG_C
init|=
literal|0x0002
block|,
name|EH_LANG_Ada83
init|=
literal|0x0003
block|,
name|EH_LANG_C_plus_plus
init|=
literal|0x0004
block|,
name|EH_LANG_Cobol74
init|=
literal|0x0005
block|,
name|EH_LANG_Cobol85
init|=
literal|0x0006
block|,
name|EH_LANG_Fortran77
init|=
literal|0x0007
block|,
name|EH_LANG_Fortran90
init|=
literal|0x0008
block|,
name|EH_LANG_Pascal83
init|=
literal|0x0009
block|,
name|EH_LANG_Modula2
init|=
literal|0x000a
block|,
name|EH_LANG_Java
init|=
literal|0x000b
block|,
name|EH_LANG_Mips_Assembler
init|=
literal|0x8001
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EH_TABLE_LOOKUP */
end_comment

end_unit

