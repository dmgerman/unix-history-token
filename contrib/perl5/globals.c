begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"INTERN.h"
end_include

begin_define
define|#
directive|define
name|PERL_IN_GLOBALS_C
end_define

begin_include
include|#
directive|include
file|"perl.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_undef
undef|#
directive|undef
name|PERLVAR
end_undef

begin_define
define|#
directive|define
name|PERLVAR
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
end_define

begin_undef
undef|#
directive|undef
name|PERLVARA
end_undef

begin_define
define|#
directive|define
name|PERLVARA
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|,
name|y
parameter_list|)
end_define

begin_undef
undef|#
directive|undef
name|PERLVARI
end_undef

begin_define
define|#
directive|define
name|PERLVARI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|interp.x = z;
end_define

begin_undef
undef|#
directive|undef
name|PERLVARIC
end_undef

begin_define
define|#
directive|define
name|PERLVARIC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|interp.x = z;
end_define

begin_expr_stmt
name|CPerlObj
operator|::
name|CPerlObj
argument_list|(
argument|IPerlMem* ipM
argument_list|,
argument|IPerlMem* ipMS
argument_list|,
argument|IPerlMem* ipMP
argument_list|,
argument|IPerlEnv* ipE
argument_list|,
argument|IPerlStdIO* ipStd
argument_list|,
argument|IPerlLIO* ipLIO
argument_list|,
argument|IPerlDir* ipD
argument_list|,
argument|IPerlSock* ipS
argument_list|,
argument|IPerlProc* ipP
argument_list|)
block|{
name|memset
argument_list|(
operator|(
operator|(
name|char
operator|*
operator|)
name|this
operator|)
operator|+
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|CPerlObj
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|void
operator|*
argument_list|)
argument_list|)
block|;
include|#
directive|include
file|"thrdvar.h"
include|#
directive|include
file|"intrpvar.h"
name|PL_Mem
operator|=
name|ipM
block|;
name|PL_MemShared
operator|=
name|ipMS
block|;
name|PL_MemParse
operator|=
name|ipMP
block|;
name|PL_Env
operator|=
name|ipE
block|;
name|PL_StdIO
operator|=
name|ipStd
block|;
name|PL_LIO
operator|=
name|ipLIO
block|;
name|PL_Dir
operator|=
name|ipD
block|;
name|PL_Sock
operator|=
name|ipS
block|;
name|PL_Proc
operator|=
name|ipP
block|; }
name|void
operator|*
name|CPerlObj
operator|::
name|operator
name|new
argument_list|(
argument|size_t nSize
argument_list|,
argument|IPerlMem *pvtbl
argument_list|)
block|{
if|if
condition|(
name|pvtbl
condition|)
return|return
name|pvtbl
operator|->
name|pMalloc
argument_list|(
name|pvtbl
argument_list|,
name|nSize
argument_list|)
return|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__MINGW32__
end_ifndef

begin_comment
comment|/* operator new is supposed to throw std::bad_alloc */
end_comment

begin_return
return|return
name|NULL
return|;
end_return

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
unit|}
ifndef|#
directive|ifndef
name|__BORLANDC__
end_ifndef

begin_expr_stmt
unit|void
name|CPerlObj
operator|::
name|operator
name|delete
argument_list|(
argument|void *pPerl
argument_list|,
argument|IPerlMem *pvtbl
argument_list|)
block|{
if|if
condition|(
name|pvtbl
condition|)
name|pvtbl
operator|->
name|pFree
argument_list|(
name|pvtbl
argument_list|,
name|pPerl
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_comment
comment|/* XXX why are these needed? */
end_comment

begin_function
name|bool
name|Perl_do_exec
parameter_list|(
name|char
modifier|*
name|cmd
parameter_list|)
block|{
return|return
name|PerlProc_Cmd
argument_list|(
name|cmd
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|int
name|CPerlObj
operator|::
name|do_aspawn
argument_list|(
argument|void *vreally
argument_list|,
argument|void **vmark
argument_list|,
argument|void **vsp
argument_list|)
block|{
return|return
name|PerlProc_aspawn
argument_list|(
name|vreally
argument_list|,
name|vmark
argument_list|,
name|vsp
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_OBJECT */
end_comment

begin_function
name|int
name|Perl_fprintf_nocontext
parameter_list|(
name|PerlIO
modifier|*
name|stream
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
block|{
name|dTHX
expr_stmt|;
name|va_list
argument_list|(
name|arglist
argument_list|)
expr_stmt|;
name|va_start
argument_list|(
name|arglist
argument_list|,
name|format
argument_list|)
expr_stmt|;
return|return
name|PerlIO_vprintf
argument_list|(
name|stream
argument_list|,
name|format
argument_list|,
name|arglist
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|Perl_printf_nocontext
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
block|{
name|dTHX
expr_stmt|;
name|va_list
argument_list|(
name|arglist
argument_list|)
expr_stmt|;
name|va_start
argument_list|(
name|arglist
argument_list|,
name|format
argument_list|)
expr_stmt|;
return|return
name|PerlIO_vprintf
argument_list|(
name|PerlIO_stdout
argument_list|()
argument_list|,
name|format
argument_list|,
name|arglist
argument_list|)
return|;
block|}
end_function

begin_include
include|#
directive|include
file|"perlapi.h"
end_include

begin_comment
comment|/* bring in PL_force_link_funcs */
end_comment

end_unit

