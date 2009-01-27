begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2003 Luigi Rizzo  * Copyright (c) 1996 Alex Nash, Paul Traina, Poul-Henning Kamp  * Copyright (c) 1994 Ugen J.S.Antsilevich  *  * Idea and grammar partially left from:  * Copyright (c) 1993 Daniel Boulet  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  *  * NEW command line interface for IP firewall facility  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Options that can be set on the command line.  * When reading commands from a file, a subset of the options can also  * be applied globally by specifying them before the file name.  * After that, each line can contain its own option that changes  * the global value.  * XXX The context is not restored after each line.  */
end_comment

begin_struct
struct|struct
name|cmdline_opts
block|{
comment|/* boolean options: */
name|int
name|do_value_as_ip
decl_stmt|;
comment|/* show table value as IP */
name|int
name|do_resolv
decl_stmt|;
comment|/* try to resolve all ip to names */
name|int
name|do_time
decl_stmt|;
comment|/* Show time stamps */
name|int
name|do_quiet
decl_stmt|;
comment|/* Be quiet in add and flush */
name|int
name|do_pipe
decl_stmt|;
comment|/* this cmd refers to a pipe */
name|int
name|do_nat
decl_stmt|;
comment|/* this cmd refers to a nat config */
name|int
name|do_dynamic
decl_stmt|;
comment|/* display dynamic rules */
name|int
name|do_expired
decl_stmt|;
comment|/* display expired dynamic rules */
name|int
name|do_compact
decl_stmt|;
comment|/* show rules in compact mode */
name|int
name|do_force
decl_stmt|;
comment|/* do not ask for confirmation */
name|int
name|show_sets
decl_stmt|;
comment|/* display the set each rule belongs to */
name|int
name|test_only
decl_stmt|;
comment|/* only check syntax */
name|int
name|comment_only
decl_stmt|;
comment|/* only print action and comment */
name|int
name|verbose
decl_stmt|;
comment|/* be verbose on some commands */
comment|/* The options below can have multiple values. */
name|int
name|do_sort
decl_stmt|;
comment|/* field to sort results (0 = no) */
comment|/* valid fields are 1 and above */
name|int
name|use_set
decl_stmt|;
comment|/* work with specified set number */
comment|/* 0 means all sets, otherwise apply to set use_set - 1 */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|cmdline_opts
name|co
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * _s_x is a structure that stores a string<-> token pairs, used in  * various places in the parser. Entries are stored in arrays,  * with an entry with s=NULL as terminator.  * The search routines are match_token() and match_value().  * Often, an element with x=0 contains an error string.  *  */
end_comment

begin_struct
struct|struct
name|_s_x
block|{
name|char
specifier|const
modifier|*
name|s
decl_stmt|;
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * the following macro returns an error message if we run out of  * arguments.  */
end_comment

begin_define
define|#
directive|define
name|NEED1
parameter_list|(
name|msg
parameter_list|)
value|{if (!ac) errx(EX_USAGE, msg);}
end_define

begin_comment
comment|/* memory allocation support */
end_comment

begin_function_decl
name|void
modifier|*
name|safe_calloc
parameter_list|(
name|size_t
name|number
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|safe_realloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* a string comparison function used for historical compatibility */
end_comment

begin_function_decl
name|int
name|_substrcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|str1
parameter_list|,
specifier|const
name|char
modifier|*
name|str2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The reserved set numer. This is a constant in ip_fw.h  * but we store it in a variable so other files do not depend  * in that header just for one constant.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|resvd_set_number
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ipfw_add
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
name|av
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_show_nat
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
modifier|*
name|av
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_config_pipe
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
modifier|*
name|av
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_config_nat
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
modifier|*
name|av
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_sets_handler
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
name|av
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_table_handler
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
name|av
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_sysctl_handler
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
name|av
index|[]
parameter_list|,
name|int
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_delete
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
name|av
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_flush
parameter_list|(
name|int
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_zero
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
name|av
index|[]
parameter_list|,
name|int
name|optname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ipfw_list
parameter_list|(
name|int
name|ac
parameter_list|,
name|char
modifier|*
name|av
index|[]
parameter_list|,
name|int
name|show_counters
parameter_list|)
function_decl|;
end_function_decl

end_unit

