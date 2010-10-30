begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// gold.h -- general definitions for gold   -*- C++ -*-
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_GOLD_H
end_ifndef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_NLS
end_ifdef

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|gettext (String)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|gettext_noop
end_ifdef

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|gettext_noop (String)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|gettext
parameter_list|(
name|Msgid
parameter_list|)
value|(Msgid)
end_define

begin_define
define|#
directive|define
name|dgettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid
parameter_list|)
value|(Msgid)
end_define

begin_define
define|#
directive|define
name|dcgettext
parameter_list|(
name|Domainname
parameter_list|,
name|Msgid
parameter_list|,
name|Category
parameter_list|)
value|(Msgid)
end_define

begin_define
define|#
directive|define
name|textdomain
parameter_list|(
name|Domainname
parameter_list|)
value|while (0)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|bindtextdomain
parameter_list|(
name|Domainname
parameter_list|,
name|Dirname
parameter_list|)
value|while (0)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_define
define|#
directive|define
name|N_
parameter_list|(
name|String
parameter_list|)
value|(String)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Figure out how to get a hash set and a hash map.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TR1_UNORDERED_SET
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_TR1_UNORDERED_MAP
argument_list|)
end_if

begin_include
include|#
directive|include
file|<tr1/unordered_set>
end_include

begin_include
include|#
directive|include
file|<tr1/unordered_map>
end_include

begin_comment
comment|// We need a template typedef here.
end_comment

begin_define
define|#
directive|define
name|Unordered_set
value|std::tr1::unordered_set
end_define

begin_define
define|#
directive|define
name|Unordered_map
value|std::tr1::unordered_map
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_EXT_HASH_MAP
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_EXT_HASH_SET
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<ext/hash_map>
end_include

begin_include
include|#
directive|include
file|<ext/hash_set>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_define
define|#
directive|define
name|Unordered_set
value|__gnu_cxx::hash_set
end_define

begin_define
define|#
directive|define
name|Unordered_map
value|__gnu_cxx::hash_map
end_define

begin_decl_stmt
name|namespace
name|__gnu_cxx
block|{
name|template
operator|<
operator|>
expr|struct
name|hash
operator|<
name|std
operator|::
name|string
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|std
operator|::
name|string
name|s
operator|)
specifier|const
block|{
return|return
name|__stl_hash_string
argument_list|(
name|s
operator|.
name|c_str
argument_list|()
argument_list|)
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|hash
operator|<
name|T
operator|*
operator|>
block|{
name|size_t
name|operator
argument_list|()
operator|(
name|T
operator|*
name|p
operator|)
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|size_t
operator|>
operator|(
name|p
operator|)
return|;
block|}
expr|}
block|;  }
else|#
directive|else
comment|// The fallback is to just use set and map.
include|#
directive|include
file|<set>
include|#
directive|include
file|<map>
define|#
directive|define
name|Unordered_set
value|std::set
define|#
directive|define
name|Unordered_map
value|std::map
endif|#
directive|endif
name|namespace
name|gold
block|{
comment|// This is a hack to work around a problem with older versions of g++.
comment|// The problem is that they don't support calling a member template by
comment|// specifying the template parameters.  It works to pass in an
comment|// argument for argument dependent lookup.
comment|// To use this, the member template method declaration should put
comment|// ACCEPT_SIZE or ACCEPT_SIZE_ENDIAN after the last parameter.  If the
comment|// method takes no parameters, use ACCEPT_SIZE_ONLY or
comment|// ACCEPT_SIZE_ENDIAN_ONLY.
comment|// When calling the method, instead of using fn<size>, use fn
comment|// SELECT_SIZE_NAME or SELECT_SIZE_ENDIAN_NAME.  And after the last
comment|// argument, put SELECT_SIZE(size) or SELECT_SIZE_ENDIAN(size,
comment|// big_endian).  If there is only one argment, use the _ONLY variants.
ifdef|#
directive|ifdef
name|HAVE_MEMBER_TEMPLATE_SPECIFICATIONS
define|#
directive|define
name|SELECT_SIZE_NAME
parameter_list|(
name|size
parameter_list|)
value|<size>
define|#
directive|define
name|SELECT_SIZE
parameter_list|(
name|size
parameter_list|)
define|#
directive|define
name|SELECT_SIZE_ONLY
parameter_list|(
name|size
parameter_list|)
define|#
directive|define
name|ACCEPT_SIZE
define|#
directive|define
name|ACCEPT_SIZE_ONLY
define|#
directive|define
name|ACCEPT_SIZE_EXPLICIT
parameter_list|(
name|size
parameter_list|)
define|#
directive|define
name|SELECT_SIZE_ENDIAN_NAME
parameter_list|(
name|size
parameter_list|,
name|big_endian
parameter_list|)
value|<size, big_endian>
define|#
directive|define
name|SELECT_SIZE_ENDIAN
parameter_list|(
name|size
parameter_list|,
name|big_endian
parameter_list|)
define|#
directive|define
name|SELECT_SIZE_ENDIAN_ONLY
parameter_list|(
name|size
parameter_list|,
name|big_endian
parameter_list|)
define|#
directive|define
name|ACCEPT_SIZE_ENDIAN
define|#
directive|define
name|ACCEPT_SIZE_ENDIAN_ONLY
define|#
directive|define
name|ACCEPT_SIZE_ENDIAN_EXPLICIT
parameter_list|(
name|size
parameter_list|,
name|big_endian
parameter_list|)
else|#
directive|else
comment|// !defined(HAVE_MEMBER_TEMPLATE_SPECIFICATIONS)
name|template
operator|<
name|int
name|size
operator|>
name|class
name|Select_size
block|{ }
block|;
name|template
operator|<
name|int
name|size
block|,
name|bool
name|big_endian
operator|>
name|class
name|Select_size_endian
block|{ }
block|;
define|#
directive|define
name|SELECT_SIZE_NAME
parameter_list|(
name|size
parameter_list|)
define|#
directive|define
name|SELECT_SIZE
parameter_list|(
name|size
parameter_list|)
value|, Select_size<size>()
define|#
directive|define
name|SELECT_SIZE_ONLY
parameter_list|(
name|size
parameter_list|)
value|Select_size<size>()
define|#
directive|define
name|ACCEPT_SIZE
value|, Select_size<size>
define|#
directive|define
name|ACCEPT_SIZE_ONLY
value|Select_size<size>
define|#
directive|define
name|ACCEPT_SIZE_EXPLICIT
parameter_list|(
name|size
parameter_list|)
value|, Select_size<size>
define|#
directive|define
name|SELECT_SIZE_ENDIAN_NAME
parameter_list|(
name|size
parameter_list|,
name|big_endian
parameter_list|)
define|#
directive|define
name|SELECT_SIZE_ENDIAN
parameter_list|(
name|size
parameter_list|,
name|big_endian
parameter_list|)
define|\
value|, Select_size_endian<size, big_endian>()
define|#
directive|define
name|SELECT_SIZE_ENDIAN_ONLY
parameter_list|(
name|size
parameter_list|,
name|big_endian
parameter_list|)
define|\
value|Select_size_endian<size, big_endian>()
define|#
directive|define
name|ACCEPT_SIZE_ENDIAN
value|, Select_size_endian<size, big_endian>
define|#
directive|define
name|ACCEPT_SIZE_ENDIAN_ONLY
value|Select_size_endian<size, big_endian>
define|#
directive|define
name|ACCEPT_SIZE_ENDIAN_EXPLICIT
parameter_list|(
name|size
parameter_list|,
name|big_endian
parameter_list|)
define|\
value|, Select_size_endian<size, big_endian>
endif|#
directive|endif
comment|// !defined(HAVE_MEMBER_TEMPLATE_SPECIFICATIONS)
block|}
comment|// End namespace gold.
name|namespace
name|gold
block|{
name|class
name|General_options
block|;
name|class
name|Command_line
block|;
name|class
name|Input_argument_list
block|;
name|class
name|Dirsearch
block|;
name|class
name|Input_objects
block|;
name|class
name|Symbol_table
block|;
name|class
name|Layout
block|;
name|class
name|Workqueue
block|;
name|class
name|Output_file
block|;
comment|// The name of the program as used in error messages.
specifier|extern
specifier|const
name|char
operator|*
name|program_name
block|;
comment|// This function is called to exit the program.  Status is true to
comment|// exit success (0) and false to exit failure (1).
specifier|extern
name|void
name|gold_exit
argument_list|(
argument|bool status
argument_list|)
name|ATTRIBUTE_NORETURN
block|;
comment|// This function is called to emit an unexpected error message and a
comment|// newline, and then exit with failure.  If PERRNO is true, it reports
comment|// the error in errno.
specifier|extern
name|void
name|gold_fatal
argument_list|(
argument|const char* msg
argument_list|,
argument|bool perrno
argument_list|)
name|ATTRIBUTE_NORETURN
block|;
comment|// This is function is called in some cases if we run out of memory.
specifier|extern
name|void
name|gold_nomem
argument_list|()
name|ATTRIBUTE_NORETURN
block|;
comment|// This macro and function are used in cases which can not arise if
comment|// the code is written correctly.
define|#
directive|define
name|gold_unreachable
parameter_list|()
define|\
value|(gold::do_gold_unreachable(__FILE__, __LINE__, __FUNCTION__))
specifier|extern
name|void
name|do_gold_unreachable
argument_list|(
argument|const char*
argument_list|,
argument|int
argument_list|,
argument|const char*
argument_list|)
name|ATTRIBUTE_NORETURN
block|;
comment|// Assertion check.
define|#
directive|define
name|gold_assert
parameter_list|(
name|expr
parameter_list|)
value|((void)(!(expr) ? gold_unreachable(), 0 : 0))
comment|// Queue up the first set of tasks.
specifier|extern
name|void
name|queue_initial_tasks
argument_list|(
specifier|const
name|General_options
operator|&
argument_list|,
specifier|const
name|Dirsearch
operator|&
argument_list|,
specifier|const
name|Command_line
operator|&
argument_list|,
name|Workqueue
operator|*
argument_list|,
name|Input_objects
operator|*
argument_list|,
name|Symbol_table
operator|*
argument_list|,
name|Layout
operator|*
argument_list|)
block|;
comment|// Queue up the middle set of tasks.
specifier|extern
name|void
name|queue_middle_tasks
argument_list|(
specifier|const
name|General_options
operator|&
argument_list|,
specifier|const
name|Input_objects
operator|*
argument_list|,
name|Symbol_table
operator|*
argument_list|,
name|Layout
operator|*
argument_list|,
name|Workqueue
operator|*
argument_list|)
block|;
comment|// Queue up the final set of tasks.
specifier|extern
name|void
name|queue_final_tasks
argument_list|(
specifier|const
name|General_options
operator|&
argument_list|,
specifier|const
name|Input_objects
operator|*
argument_list|,
specifier|const
name|Symbol_table
operator|*
argument_list|,
specifier|const
name|Layout
operator|*
argument_list|,
name|Workqueue
operator|*
argument_list|,
name|Output_file
operator|*
name|of
argument_list|)
block|;  }
end_decl_stmt

begin_comment
comment|// End namespace gold.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_GOLD_H)
end_comment

end_unit

