begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** rexp.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*$Log:	rexp.h,v $  * Revision 3.6  92/01/21  17:31:45  brennan  * moved ison() macro out of rexp[23].c  *   * Revision 3.5  91/10/29  10:53:55  brennan  * SIZE_T  *   * Revision 3.4  91/08/13  09:10:02  brennan  * VERSION .9994  *   * Revision 3.3  91/06/15  09:40:25  brennan  * gcc defines __STDC__ but might not have stdlib.h  *   * Revision 3.2  91/06/10  16:18:19  brennan  * changes for V7  *   * Revision 3.1  91/06/07  10:33:18  brennan  * VERSION 0.995  *   * Revision 1.3  91/06/05  08:57:57  brennan  * removed RE_xmalloc()  *   * Revision 1.2  91/06/03  07:23:26  brennan  * changed type of RE_error_trap  *   * Revision 1.1  91/06/03  07:05:41  brennan  * Initial revision  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REXP_H
end_ifndef

begin_define
define|#
directive|define
name|REXP_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|THINK_C
end_ifdef

begin_define
define|#
directive|define
name|MAWK
end_define

begin_comment
comment|/* THINK C doesn't allow compile-time definitions */
end_comment

begin_define
define|#
directive|define
name|SIZE_T
parameter_list|(
name|x
parameter_list|)
value|(size_t)(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_T
end_ifndef

begin_define
define|#
directive|define
name|SIZE_T
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_function_decl
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|PROTO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|name
parameter_list|,
name|args
parameter_list|)
value|name  args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|name
parameter_list|,
name|args
parameter_list|)
value|name()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOID
value|char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|VOID
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|free
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|VOID
modifier|*
name|PROTO
argument_list|(
name|RE_malloc
argument_list|,
operator|(
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|VOID
modifier|*
name|PROTO
argument_list|(
name|RE_realloc
argument_list|,
operator|(
name|void
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  finite machine  state types  */
end_comment

begin_define
define|#
directive|define
name|M_STR
value|0
end_define

begin_define
define|#
directive|define
name|M_CLASS
value|1
end_define

begin_define
define|#
directive|define
name|M_ANY
value|2
end_define

begin_define
define|#
directive|define
name|M_START
value|3
end_define

begin_define
define|#
directive|define
name|M_END
value|4
end_define

begin_define
define|#
directive|define
name|M_U
value|5
end_define

begin_define
define|#
directive|define
name|M_1J
value|6
end_define

begin_define
define|#
directive|define
name|M_2JA
value|7
end_define

begin_define
define|#
directive|define
name|M_2JB
value|8
end_define

begin_define
define|#
directive|define
name|M_ACCEPT
value|9
end_define

begin_define
define|#
directive|define
name|U_ON
value|10
end_define

begin_define
define|#
directive|define
name|U_OFF
value|0
end_define

begin_define
define|#
directive|define
name|END_OFF
value|0
end_define

begin_define
define|#
directive|define
name|END_ON
value|(2*U_ON)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BV
index|[
literal|32
index|]
typedef|;
end_typedef

begin_comment
comment|/* bit vector */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|type
decl_stmt|;
name|unsigned
name|char
name|len
decl_stmt|;
comment|/* used for M_STR  */
union|union
block|{
name|char
modifier|*
name|str
decl_stmt|;
comment|/* string */
name|BV
modifier|*
name|bvp
decl_stmt|;
comment|/*  class  */
name|int
name|jump
decl_stmt|;
block|}
name|data
union|;
block|}
name|STATE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|STATESZ
value|(sizeof(STATE))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|STATE
modifier|*
name|start
decl_stmt|,
modifier|*
name|stop
decl_stmt|;
block|}
name|MACHINE
typedef|;
end_typedef

begin_comment
comment|/*  tokens   */
end_comment

begin_define
define|#
directive|define
name|T_OR
value|1
end_define

begin_comment
comment|/* | */
end_comment

begin_define
define|#
directive|define
name|T_CAT
value|2
end_define

begin_define
define|#
directive|define
name|T_STAR
value|3
end_define

begin_comment
comment|/* * */
end_comment

begin_define
define|#
directive|define
name|T_PLUS
value|4
end_define

begin_comment
comment|/* + */
end_comment

begin_define
define|#
directive|define
name|T_Q
value|5
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|T_LP
value|6
end_define

begin_comment
comment|/* ( */
end_comment

begin_define
define|#
directive|define
name|T_RP
value|7
end_define

begin_comment
comment|/* ) */
end_comment

begin_define
define|#
directive|define
name|T_START
value|8
end_define

begin_comment
comment|/* ^ */
end_comment

begin_define
define|#
directive|define
name|T_END
value|9
end_define

begin_comment
comment|/* $ */
end_comment

begin_define
define|#
directive|define
name|T_ANY
value|10
end_define

begin_comment
comment|/* . */
end_comment

begin_define
define|#
directive|define
name|T_CLASS
value|11
end_define

begin_comment
comment|/* starts with [ */
end_comment

begin_define
define|#
directive|define
name|T_SLASH
value|12
end_define

begin_comment
comment|/*  \  */
end_comment

begin_define
define|#
directive|define
name|T_CHAR
value|13
end_define

begin_comment
comment|/* all the rest */
end_comment

begin_define
define|#
directive|define
name|T_STR
value|14
end_define

begin_define
define|#
directive|define
name|T_U
value|15
end_define

begin_comment
comment|/*  precedences and error codes  */
end_comment

begin_define
define|#
directive|define
name|L
value|0
end_define

begin_define
define|#
directive|define
name|EQ
value|1
end_define

begin_define
define|#
directive|define
name|G
value|2
end_define

begin_define
define|#
directive|define
name|E1
value|(-1)
end_define

begin_define
define|#
directive|define
name|E2
value|(-2)
end_define

begin_define
define|#
directive|define
name|E3
value|(-3)
end_define

begin_define
define|#
directive|define
name|E4
value|(-4)
end_define

begin_define
define|#
directive|define
name|E5
value|(-5)
end_define

begin_define
define|#
directive|define
name|E6
value|(-6)
end_define

begin_define
define|#
directive|define
name|E7
value|(-7)
end_define

begin_define
define|#
directive|define
name|MEMORY_FAILURE
value|5
end_define

begin_define
define|#
directive|define
name|ison
parameter_list|(
name|b
parameter_list|,
name|x
parameter_list|)
value|((b)[((unsigned char)(x))>>3]& (1<<((x)&7)))
end_define

begin_comment
comment|/* struct for the run time stack */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|STATE
modifier|*
name|m
decl_stmt|;
comment|/*   save the machine ptr */
name|int
name|u
decl_stmt|;
comment|/*   save the u_flag */
name|char
modifier|*
name|s
decl_stmt|;
comment|/*   save the active string ptr */
name|char
modifier|*
name|ss
decl_stmt|;
comment|/*   save the match start -- only used by REmatch */
block|}
name|RT_STATE
typedef|;
end_typedef

begin_comment
comment|/* run time state */
end_comment

begin_comment
comment|/*  error  trap   */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|REerrno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|RE_error_trap
argument_list|,
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MACHINE
name|PROTO
argument_list|(
name|RE_u
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MACHINE
name|PROTO
argument_list|(
name|RE_start
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MACHINE
name|PROTO
argument_list|(
name|RE_end
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MACHINE
name|PROTO
argument_list|(
name|RE_any
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MACHINE
name|PROTO
argument_list|(
name|RE_str
argument_list|,
operator|(
name|char
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MACHINE
name|PROTO
argument_list|(
name|RE_class
argument_list|,
operator|(
name|BV
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|RE_cat
argument_list|,
operator|(
name|MACHINE
operator|*
operator|,
name|MACHINE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|RE_or
argument_list|,
operator|(
name|MACHINE
operator|*
operator|,
name|MACHINE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|RE_close
argument_list|,
operator|(
name|MACHINE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|RE_poscl
argument_list|,
operator|(
name|MACHINE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|RE_01
argument_list|,
operator|(
name|MACHINE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|RE_panic
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|PROTO
argument_list|(
name|str_str
argument_list|,
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|RE_lex_init
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|RE_lex
argument_list|,
operator|(
name|MACHINE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|RE_run_stack_init
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|RT_STATE
modifier|*
name|PROTO
argument_list|(
name|RE_new_run_stack
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REXP_H  */
end_comment

end_unit

