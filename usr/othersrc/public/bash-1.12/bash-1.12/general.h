begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* general.h -- defines that everybody likes to use. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_GENERAL_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_GENERAL_
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NULL
argument_list|)
end_if

begin_define
define|#
directive|define
name|NULL
value|0x0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|savestring
end_ifndef

begin_define
define|#
directive|define
name|savestring
parameter_list|(
name|x
parameter_list|)
value|(char *)strcpy (xmalloc (1 + strlen (x)), (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|whitespace
end_ifndef

begin_define
define|#
directive|define
name|whitespace
parameter_list|(
name|c
parameter_list|)
value|(((c) == ' ') || ((c) == '\t'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|digit
end_ifndef

begin_define
define|#
directive|define
name|digit
parameter_list|(
name|c
parameter_list|)
value|((c)>= '0'&& (c)<= '9')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|isletter
end_ifndef

begin_define
define|#
directive|define
name|isletter
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 'A'&& (c)<= 'Z') || ((c)>= 'a'&& (c)<= 'z'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|digit_value
end_ifndef

begin_define
define|#
directive|define
name|digit_value
parameter_list|(
name|c
parameter_list|)
value|((c) - '0')
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
name|__STDC__
argument_list|)
end_if

begin_decl_stmt
name|char
modifier|*
name|index
argument_list|()
decl_stmt|,
modifier|*
name|rindex
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|member
end_ifndef

begin_define
define|#
directive|define
name|member
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|(int)((c) ? index ((s), (c)) : 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* All structs which contain a `next' field should have that field    as the first field in the struct.  This means that functions    can be written to handle the general case for linked lists. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|g_list
block|{
name|struct
name|g_list
modifier|*
name|next
decl_stmt|;
block|}
name|GENERIC_LIST
typedef|;
end_typedef

begin_comment
comment|/* Here is a generic structure for associating character strings    with integers.  It is used in the parser for shell tokenization. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|word
decl_stmt|;
name|int
name|token
decl_stmt|;
block|}
name|STRING_INT_ALIST
typedef|;
end_typedef

begin_comment
comment|/* String comparisons that possibly save a function call each. */
end_comment

begin_define
define|#
directive|define
name|STREQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)[0] == (b)[0]&& strcmp(a, b) == 0)
end_define

begin_define
define|#
directive|define
name|STREQN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|n
parameter_list|)
value|((a)[0] == (b)[0]&& strncmp(a, b, n) == 0)
end_define

begin_comment
comment|/* Function pointers can be declared as (Function *)foo. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FUNCTION_DEF
argument_list|)
end_if

begin_define
define|#
directive|define
name|__FUNCTION_DEF
end_define

begin_typedef
typedef|typedef
name|int
name|Function
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|VFunction
parameter_list|()
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FUNCTION_DEF */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VOID_SIGHANDLER
argument_list|)
end_if

begin_define
define|#
directive|define
name|sighandler
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sighandler
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|sighandler
name|SigHandler
parameter_list|()
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|NOW
value|((time_t) time ((time_t *) 0))
end_define

begin_comment
comment|/* Some defines for calling file status functions. */
end_comment

begin_define
define|#
directive|define
name|FS_EXISTS
value|0x1
end_define

begin_define
define|#
directive|define
name|FS_EXECABLE
value|0x2
end_define

begin_define
define|#
directive|define
name|FS_EXEC_PREFERRED
value|0x4
end_define

begin_define
define|#
directive|define
name|FS_EXEC_ONLY
value|0x8
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xmalloc
argument_list|()
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|xrealloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|itos
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GENERAL_ */
end_comment

end_unit

