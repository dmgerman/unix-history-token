begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"quipu/util.h"
end_include

begin_include
include|#
directive|include
file|"quipu/common.h"
end_include

begin_include
include|#
directive|include
file|"quipu/entry.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"usr.dirent.h"
end_include

begin_include
include|#
directive|include
file|"tailor.h"
end_include

begin_include
include|#
directive|include
file|"sequence.h"
end_include

begin_include
include|#
directive|include
file|"filt.h"
end_include

begin_include
include|#
directive|include
file|"y.tab.h"
end_include

begin_decl_stmt
name|void
name|user_tailor
argument_list|()
decl_stmt|,
name|main_help
argument_list|()
decl_stmt|,
name|main_bind
argument_list|()
decl_stmt|,
name|cnnct_quit
argument_list|()
decl_stmt|,
name|cnnct_bind
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rd_start
argument_list|()
decl_stmt|,
name|back_start
argument_list|()
decl_stmt|,
name|widen
argument_list|()
decl_stmt|,
name|set_default_type
argument_list|()
decl_stmt|,
name|list_start
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|rdn2str
argument_list|()
decl_stmt|,
name|srch_start
argument_list|()
decl_stmt|,
name|dn2buf
argument_list|()
decl_stmt|,
name|read_print
argument_list|()
decl_stmt|,
name|quipu_print
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|quipu_error
argument_list|()
decl_stmt|,
name|returnmain
argument_list|()
decl_stmt|,
name|get_listed_object
argument_list|()
decl_stmt|,
name|scrollbar
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|make_friendly
argument_list|()
decl_stmt|,
name|goto_addr
argument_list|()
decl_stmt|,
name|entry2str
argument_list|()
decl_stmt|,
name|rfc2jnt
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|isleafnode
argument_list|()
decl_stmt|,
name|issubstr
argument_list|()
decl_stmt|,
name|indexstring
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|attrcomp
modifier|*
name|sort_attrs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|str_seq
name|SortList
parameter_list|()
function_decl|;
end_function_decl

end_unit

