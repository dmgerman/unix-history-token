begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: util.h,v 7.0 86/10/08 15:14:37 lwall Exp $ */
end_comment

begin_comment
comment|/* $Log:	util.h,v $  * Revision 7.0  86/10/08  15:14:37  lwall  * Split into separate files.  Added amoebas and pirates.  *   */
end_comment

begin_if
if|#
directive|if
name|RANDBITS
operator|<
literal|15
operator|||
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_define
define|#
directive|define
name|rand_mod
parameter_list|(
name|m
parameter_list|)
value|getpid()
end_define

begin_define
define|#
directive|define
name|RANDRAND
value|0.0
end_define

begin_define
define|#
directive|define
name|HALFRAND
value|0
end_define

begin_define
define|#
directive|define
name|myrand
parameter_list|()
value|getpid()
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|RANDBITS
operator|==
literal|15
end_if

begin_comment
comment|/* 15 bits of rand()? */
end_comment

begin_define
define|#
directive|define
name|RANDRAND
value|268435456.0
end_define

begin_comment
comment|/* that's 2**28 */
end_comment

begin_define
define|#
directive|define
name|HALFRAND
value|0x4000
end_define

begin_comment
comment|/* that's 2**14 */
end_comment

begin_function_decl
name|int
name|rand
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|myrand
parameter_list|()
value|(rand()&32767)
end_define

begin_define
define|#
directive|define
name|rand_mod
parameter_list|(
name|m
parameter_list|)
value|((int)((double)myrand() / 32768.0 * ((double)(m))))
end_define

begin_comment
comment|/* pick number in 0..m-1 */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|RANDBITS
operator|<
literal|31
end_if

begin_comment
comment|/* 16 bits of rand()? */
end_comment

begin_define
define|#
directive|define
name|RANDRAND
value|1073741824.0
end_define

begin_comment
comment|/* that's 2**30 */
end_comment

begin_define
define|#
directive|define
name|HALFRAND
value|0x8000
end_define

begin_comment
comment|/* that's 2**15 */
end_comment

begin_function_decl
name|unsigned
name|rand
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|myrand
parameter_list|()
value|(rand()&65535)
end_define

begin_define
define|#
directive|define
name|rand_mod
parameter_list|(
name|m
parameter_list|)
value|((int)((double)myrand() / 65536.0 * ((double)(m))))
end_define

begin_comment
comment|/* pick number in 0..m-1 */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* assume 31 bits */
end_comment

begin_define
define|#
directive|define
name|RANDRAND
value|1152921504606846976.0
end_define

begin_comment
comment|/* that's 2**60 */
end_comment

begin_define
define|#
directive|define
name|HALFRAND
value|0x40000000
end_define

begin_comment
comment|/* that's 2**30 */
end_comment

begin_function_decl
name|long
name|rand
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|myrand
parameter_list|()
value|rand()
end_define

begin_define
define|#
directive|define
name|rand_mod
parameter_list|(
name|m
parameter_list|)
value|((myrand() / 37) % (m))
end_define

begin_comment
comment|/* pick number in 0..m-1 */
end_comment

begin_comment
comment|/*  * The reason for the /37 above is that our random number generator yields  * successive evens and odds, for some reason.  This makes strange star maps.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* we get fractions of seconds from calling ftime on timebuf */
end_comment

begin_decl_stmt
name|EXT
name|struct
name|timeb
name|timebuf
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|roundsleep
parameter_list|(
name|x
parameter_list|)
value|(ftime(&timebuf),sleep(timebuf.millitm> 500?x+1:x))
end_define

begin_function_decl
name|void
name|movc3
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|no_can_do
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|exdis
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|EXT
name|bool
name|waiting
name|INIT
parameter_list|(
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* are we waiting for subprocess (in doshell)? */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOTDEF
end_ifdef

begin_decl_stmt
name|EXT
name|int
name|len_last_line_got
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* strlen of some_buf after */
end_comment

begin_comment
comment|/*  some_buf = get_a_line(bufptr,buffersize,fp) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NOTDEF
end_ifdef

begin_comment
comment|/* is the string for makedir a directory name or a filename? */
end_comment

begin_define
define|#
directive|define
name|MD_DIR
value|0
end_define

begin_define
define|#
directive|define
name|MD_FILE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|util_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|safemalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|safecpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cpytill
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|instr
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SETUIDGID
end_ifdef

begin_function_decl
name|int
name|eaccess
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|getwd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prexit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|savestr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getval
parameter_list|()
function_decl|;
end_function_decl

end_unit

