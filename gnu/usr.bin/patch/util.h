begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$  *  * $Log: util.h,v $  * Revision 2.0  86/09/17  15:40:06  lwall  * Baseline for netwide release.  *  */
end_comment

begin_comment
comment|/* and for those machine that can't handle a variable argument list */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CANVARARG
end_ifdef

begin_define
define|#
directive|define
name|say1
value|say
end_define

begin_define
define|#
directive|define
name|say2
value|say
end_define

begin_define
define|#
directive|define
name|say3
value|say
end_define

begin_define
define|#
directive|define
name|say4
value|say
end_define

begin_define
define|#
directive|define
name|ask1
value|ask
end_define

begin_define
define|#
directive|define
name|ask2
value|ask
end_define

begin_define
define|#
directive|define
name|ask3
value|ask
end_define

begin_define
define|#
directive|define
name|ask4
value|ask
end_define

begin_define
define|#
directive|define
name|fatal1
value|fatal
end_define

begin_define
define|#
directive|define
name|fatal2
value|fatal
end_define

begin_define
define|#
directive|define
name|fatal3
value|fatal
end_define

begin_define
define|#
directive|define
name|fatal4
value|fatal
end_define

begin_define
define|#
directive|define
name|pfatal1
value|pfatal
end_define

begin_define
define|#
directive|define
name|pfatal2
value|pfatal
end_define

begin_define
define|#
directive|define
name|pfatal3
value|pfatal
end_define

begin_define
define|#
directive|define
name|pfatal4
value|pfatal
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* hope they allow multi-line macro actual arguments */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|say1
parameter_list|(
name|a
parameter_list|)
value|say(a, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|say2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|say(a, (b)==(b), 0, 0)
end_define

begin_define
define|#
directive|define
name|say3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|say(a, (b)==(b), (c)==(c), 0)
end_define

begin_define
define|#
directive|define
name|say4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|say(a, (b)==(b), (c)==(c), (d)==(d))
end_define

begin_define
define|#
directive|define
name|ask1
parameter_list|(
name|a
parameter_list|)
value|ask(a, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|ask2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ask(a, (b)==(b), 0, 0)
end_define

begin_define
define|#
directive|define
name|ask3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|ask(a, (b)==(b), (c)==(c), 0)
end_define

begin_define
define|#
directive|define
name|ask4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|ask(a, (b)==(b), (c)==(c), (d)==(d))
end_define

begin_define
define|#
directive|define
name|fatal1
parameter_list|(
name|a
parameter_list|)
value|fatal(a, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|fatal2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|fatal(a, (b)==(b), 0, 0)
end_define

begin_define
define|#
directive|define
name|fatal3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|fatal(a, (b)==(b), (c)==(c), 0)
end_define

begin_define
define|#
directive|define
name|fatal4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|fatal(a, (b)==(b), (c)==(c), (d)==(d))
end_define

begin_define
define|#
directive|define
name|pfatal1
parameter_list|(
name|a
parameter_list|)
value|pfatal(a, 0, 0, 0)
end_define

begin_define
define|#
directive|define
name|pfatal2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|pfatal(a, (b)==(b), 0, 0)
end_define

begin_define
define|#
directive|define
name|pfatal3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|pfatal(a, (b)==(b), (c)==(c), 0)
end_define

begin_define
define|#
directive|define
name|pfatal4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|pfatal(a, (b)==(b), (c)==(c), (d)==(d))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* lint */
end_comment

begin_comment
comment|/* if this doesn't work, try defining CANVARARG above */
end_comment

begin_define
define|#
directive|define
name|say1
parameter_list|(
name|a
parameter_list|)
value|say(a, Nullch, Nullch, Nullch)
end_define

begin_define
define|#
directive|define
name|say2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|say(a, b, Nullch, Nullch)
end_define

begin_define
define|#
directive|define
name|say3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|say(a, b, c, Nullch)
end_define

begin_define
define|#
directive|define
name|say4
value|say
end_define

begin_define
define|#
directive|define
name|ask1
parameter_list|(
name|a
parameter_list|)
value|ask(a, Nullch, Nullch, Nullch)
end_define

begin_define
define|#
directive|define
name|ask2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ask(a, b, Nullch, Nullch)
end_define

begin_define
define|#
directive|define
name|ask3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|ask(a, b, c, Nullch)
end_define

begin_define
define|#
directive|define
name|ask4
value|ask
end_define

begin_define
define|#
directive|define
name|fatal1
parameter_list|(
name|a
parameter_list|)
value|fatal(a, Nullch, Nullch, Nullch)
end_define

begin_define
define|#
directive|define
name|fatal2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|fatal(a, b, Nullch, Nullch)
end_define

begin_define
define|#
directive|define
name|fatal3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|fatal(a, b, c, Nullch)
end_define

begin_define
define|#
directive|define
name|fatal4
value|fatal
end_define

begin_define
define|#
directive|define
name|pfatal1
parameter_list|(
name|a
parameter_list|)
value|pfatal(a, Nullch, Nullch, Nullch)
end_define

begin_define
define|#
directive|define
name|pfatal2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|pfatal(a, b, Nullch, Nullch)
end_define

begin_define
define|#
directive|define
name|pfatal3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|pfatal(a, b, c, Nullch)
end_define

begin_define
define|#
directive|define
name|pfatal4
value|pfatal
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_comment
comment|/* if neither of the above work, join all multi-line macro calls. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|char
name|serrbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for stderr */
end_comment

begin_function_decl
name|char
modifier|*
name|fetchname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|move_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|say
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fatal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pfatal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ask
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
name|void
name|set_signals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ignore_signals
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|makedirs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|basename
parameter_list|()
function_decl|;
end_function_decl

end_unit

