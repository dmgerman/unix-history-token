begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pathalias -- by steve bellovin, as told to peter honeyman */
end_comment

begin_comment
comment|/* #define STRCHR	/* have strchr, not index -- probably system v */
end_comment

begin_comment
comment|/* #define UNAME	/* have uname() -- probably system v or 8th ed. */
end_comment

begin_comment
comment|/* #define MEMSET	/* have memset() -- probably system v or 8th ed. */
end_comment

begin_define
define|#
directive|define
name|GETHOSTNAME
end_define

begin_comment
comment|/* have gethostname() -- probably 4.2bsd */
end_comment

begin_define
define|#
directive|define
name|BZERO
end_define

begin_comment
comment|/* have bzero() -- probably 4.2bsd */
end_comment

begin_comment
comment|/* default place for dbm output of makedb (or use -o file at run-time) */
end_comment

begin_define
define|#
directive|define
name|ALIASDB
value|"/usr/new/lib/palias"
end_define

begin_comment
comment|/**************************************************************************  *									  *  * +--------------------------------------------------------------------+ *  * |									| *  * |			END OF CONFIGURATION SECTION			| *  * |									| *  * |				EDIT NO MORE				| *  * |									| *  * +--------------------------------------------------------------------+ *  *									  *  **************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAIN
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|c_sccsid
init|=
literal|"@(#)config.h	8.1 (down!honey) 86/01/19"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*lint*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*MAIN*/
end_comment

begin_comment
comment|/*  * malloc/free fine tuned for pathalias.  *  * MYMALLOC should work everwhere, so it's not a configuration  * option (anymore).  nonetheless, if you're getting strange  * core dumps (or panics!), comment out the following manifest,  * and use the inferior C library malloc/free.  *  * report problems to princeton!honey.  */
end_comment

begin_define
define|#
directive|define
name|MYMALLOC
end_define

begin_comment
comment|/**/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MYMALLOC
end_ifdef

begin_define
define|#
directive|define
name|malloc
value|mymalloc
end_define

begin_define
define|#
directive|define
name|calloc
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|malloc ((n)*(s))
end_define

begin_define
define|#
directive|define
name|free
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|cfree
parameter_list|(
name|s
parameter_list|)
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|memget
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|STRCHR
end_ifdef

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BZERO
end_ifdef

begin_define
define|#
directive|define
name|strclear
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|((void) bzero((s), (n)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*!BZERO*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MEMSET
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|memset
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|strclear
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|)
value|((void) memset((s), 0, (n)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*!MEMSET*/
end_comment

begin_function_decl
specifier|extern
name|void
name|strclear
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*MEMSET*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*BZERO*/
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|index
argument_list|()
decl_stmt|,
modifier|*
name|rindex
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

