begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_INC_PERL_XSUB_H
end_ifndef

begin_define
define|#
directive|define
name|_INC_PERL_XSUB_H
value|1
end_define

begin_comment
comment|/* first, some documentation for xsubpp-generated items */
end_comment

begin_comment
comment|/* =for apidoc Amn|char*|CLASS Variable which is setup by C<xsubpp> to indicate the  class name for a C++ XS constructor.  This is always a C<char*>.  See C<THIS>.  =for apidoc Amn|(whatever)|RETVAL Variable which is setup by C<xsubpp> to hold the return value for an  XSUB. This is always the proper type for the XSUB. See  L<perlxs/"The RETVAL Variable">.  =for apidoc Amn|(whatever)|THIS Variable which is setup by C<xsubpp> to designate the object in a C++  XSUB.  This is always the proper type for the C++ object.  See C<CLASS> and  L<perlxs/"Using XS With C++">.  =for apidoc Amn|I32|items Variable which is setup by C<xsubpp> to indicate the number of  items on the stack.  See L<perlxs/"Variable-length Parameter Lists">.  =for apidoc Amn|I32|ix Variable which is setup by C<xsubpp> to indicate which of an  XSUB's aliases was used to invoke it.  See L<perlxs/"The ALIAS: Keyword">.  =for apidoc Am|SV*|ST|int ix Used to access elements on the XSUB's stack.  =for apidoc AmU||XS Macro to declare an XSUB and its C parameter list.  This is handled by C<xsubpp>.  =for apidoc Ams||dXSARGS Sets up stack and mark pointers for an XSUB, calling dSP and dMARK.  This is usually handled automatically by C<xsubpp>.  Declares the C<items> variable to indicate the number of items on the stack.  =for apidoc Ams||dXSI32 Sets up the C<ix> variable for an XSUB which has aliases.  This is usually handled automatically by C<xsubpp>.  =cut */
end_comment

begin_define
define|#
directive|define
name|ST
parameter_list|(
name|off
parameter_list|)
value|PL_stack_base[ax + (off)]
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_DYNAMIC_LOADING
argument_list|)
end_if

begin_define
define|#
directive|define
name|XS
parameter_list|(
name|name
parameter_list|)
value|__declspec(dllexport) void name(pTHXo_ CV* cv)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XS
parameter_list|(
name|name
parameter_list|)
value|void name(pTHXo_ CV* cv)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|dXSARGS
define|\
value|dSP; dMARK;			\ 	I32 ax = mark - PL_stack_base + 1;	\ 	I32 items = sp - mark
end_define

begin_define
define|#
directive|define
name|dXSTARG
value|SV * targ = ((PL_op->op_private& OPpENTERSUB_HASTARG) \ 			     ? PAD_SV(PL_op->op_targ) : sv_newmortal())
end_define

begin_comment
comment|/* Should be used before final PUSHi etc. if not in PPCODE section. */
end_comment

begin_define
define|#
directive|define
name|XSprePUSH
value|(sp = PL_stack_base + ax - 1)
end_define

begin_define
define|#
directive|define
name|XSANY
value|CvXSUBANY(cv)
end_define

begin_define
define|#
directive|define
name|dXSI32
value|I32 ix = XSANY.any_i32
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|XSINTERFACE_CVT
parameter_list|(
name|ret
parameter_list|,
name|name
parameter_list|)
value|ret (*name)(...)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XSINTERFACE_CVT
parameter_list|(
name|ret
parameter_list|,
name|name
parameter_list|)
value|ret (*name)()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|dXSFUNCTION
parameter_list|(
name|ret
parameter_list|)
value|XSINTERFACE_CVT(ret,XSFUNCTION)
end_define

begin_define
define|#
directive|define
name|XSINTERFACE_FUNC
parameter_list|(
name|ret
parameter_list|,
name|cv
parameter_list|,
name|f
parameter_list|)
value|((XSINTERFACE_CVT(ret,cv))(f))
end_define

begin_define
define|#
directive|define
name|XSINTERFACE_FUNC_SET
parameter_list|(
name|cv
parameter_list|,
name|f
parameter_list|)
define|\
value|CvXSUBANY(cv).any_dptr = (void (*) (pTHXo_ void*))(f)
end_define

begin_comment
comment|/* Simple macros to put new mortal values onto the stack.   */
end_comment

begin_comment
comment|/* Typically used to return values from XS functions.       */
end_comment

begin_comment
comment|/* =for apidoc Am|void|XST_mIV|int pos|IV iv Place an integer into the specified position C<pos> on the stack.  The value is stored in a new mortal SV.  =for apidoc Am|void|XST_mNV|int pos|NV nv Place a double into the specified position C<pos> on the stack.  The value is stored in a new mortal SV.  =for apidoc Am|void|XST_mPV|int pos|char* str Place a copy of a string into the specified position C<pos> on the stack.  The value is stored in a new mortal SV.  =for apidoc Am|void|XST_mNO|int pos Place C<&PL_sv_no> into the specified position C<pos> on the stack.  =for apidoc Am|void|XST_mYES|int pos Place C<&PL_sv_yes> into the specified position C<pos> on the stack.  =for apidoc Am|void|XST_mUNDEF|int pos Place C<&PL_sv_undef> into the specified position C<pos> on the stack.  =for apidoc Am|void|XSRETURN|int nitems Return from XSUB, indicating number of items on the stack.  This is usually handled by C<xsubpp>.  =for apidoc Am|void|XSRETURN_IV|IV iv Return an integer from an XSUB immediately.  Uses C<XST_mIV>.  =for apidoc Am|void|XSRETURN_NV|NV nv Return an double from an XSUB immediately.  Uses C<XST_mNV>.  =for apidoc Am|void|XSRETURN_PV|char* str Return a copy of a string from an XSUB immediately.  Uses C<XST_mPV>.  =for apidoc Ams||XSRETURN_NO Return C<&PL_sv_no> from an XSUB immediately.  Uses C<XST_mNO>.  =for apidoc Ams||XSRETURN_YES Return C<&PL_sv_yes> from an XSUB immediately.  Uses C<XST_mYES>.  =for apidoc Ams||XSRETURN_UNDEF Return C<&PL_sv_undef> from an XSUB immediately.  Uses C<XST_mUNDEF>.  =for apidoc Ams||XSRETURN_EMPTY Return an empty list from an XSUB immediately.  =for apidoc AmU||newXSproto Used by C<xsubpp> to hook up XSUBs as Perl subs.  Adds Perl prototypes to the subs.  =for apidoc AmU||XS_VERSION The version identifier for an XS module.  This is usually handled automatically by C<ExtUtils::MakeMaker>.  See C<XS_VERSION_BOOTCHECK>.  =for apidoc Ams||XS_VERSION_BOOTCHECK Macro to verify that a PM module's $VERSION variable matches the XS module's C<XS_VERSION> variable.  This is usually handled automatically by C<xsubpp>.  See L<perlxs/"The VERSIONCHECK: Keyword">.  =cut */
end_comment

begin_define
define|#
directive|define
name|XST_mIV
parameter_list|(
name|i
parameter_list|,
name|v
parameter_list|)
value|(ST(i) = sv_2mortal(newSViv(v))  )
end_define

begin_define
define|#
directive|define
name|XST_mNV
parameter_list|(
name|i
parameter_list|,
name|v
parameter_list|)
value|(ST(i) = sv_2mortal(newSVnv(v))  )
end_define

begin_define
define|#
directive|define
name|XST_mPV
parameter_list|(
name|i
parameter_list|,
name|v
parameter_list|)
value|(ST(i) = sv_2mortal(newSVpv(v,0)))
end_define

begin_define
define|#
directive|define
name|XST_mPVN
parameter_list|(
name|i
parameter_list|,
name|v
parameter_list|,
name|n
parameter_list|)
value|(ST(i) = sv_2mortal(newSVpvn(v,n)))
end_define

begin_define
define|#
directive|define
name|XST_mNO
parameter_list|(
name|i
parameter_list|)
value|(ST(i) =&PL_sv_no   )
end_define

begin_define
define|#
directive|define
name|XST_mYES
parameter_list|(
name|i
parameter_list|)
value|(ST(i) =&PL_sv_yes  )
end_define

begin_define
define|#
directive|define
name|XST_mUNDEF
parameter_list|(
name|i
parameter_list|)
value|(ST(i) =&PL_sv_undef)
end_define

begin_define
define|#
directive|define
name|XSRETURN
parameter_list|(
name|off
parameter_list|)
define|\
value|STMT_START {					\ 	PL_stack_sp = PL_stack_base + ax + ((off) - 1);	\ 	return;						\     } STMT_END
end_define

begin_define
define|#
directive|define
name|XSRETURN_IV
parameter_list|(
name|v
parameter_list|)
value|STMT_START { XST_mIV(0,v);  XSRETURN(1); } STMT_END
end_define

begin_define
define|#
directive|define
name|XSRETURN_NV
parameter_list|(
name|v
parameter_list|)
value|STMT_START { XST_mNV(0,v);  XSRETURN(1); } STMT_END
end_define

begin_define
define|#
directive|define
name|XSRETURN_PV
parameter_list|(
name|v
parameter_list|)
value|STMT_START { XST_mPV(0,v);  XSRETURN(1); } STMT_END
end_define

begin_define
define|#
directive|define
name|XSRETURN_PVN
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|STMT_START { XST_mPVN(0,v,n);  XSRETURN(1); } STMT_END
end_define

begin_define
define|#
directive|define
name|XSRETURN_NO
value|STMT_START { XST_mNO(0);    XSRETURN(1); } STMT_END
end_define

begin_define
define|#
directive|define
name|XSRETURN_YES
value|STMT_START { XST_mYES(0);   XSRETURN(1); } STMT_END
end_define

begin_define
define|#
directive|define
name|XSRETURN_UNDEF
value|STMT_START { XST_mUNDEF(0); XSRETURN(1); } STMT_END
end_define

begin_define
define|#
directive|define
name|XSRETURN_EMPTY
value|STMT_START {                XSRETURN(0); } STMT_END
end_define

begin_define
define|#
directive|define
name|newXSproto
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|sv_setpv((SV*)newXS(a,b,c), d)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|XS_VERSION
end_ifdef

begin_define
define|#
directive|define
name|XS_VERSION_BOOTCHECK
define|\
value|STMT_START {							\ 	SV *tmpsv; STRLEN n_a;						\ 	char *vn = Nullch, *module = SvPV(ST(0),n_a);			\ 	if (items>= 2)
comment|/* version supplied as bootstrap arg */
value|\ 	    tmpsv = ST(1);						\ 	else {								\
comment|/* XXX GV_ADDWARN */
value|\ 	    tmpsv = get_sv(Perl_form(aTHX_ "%s::%s", module,		\ 				vn = "XS_VERSION"), FALSE);		\ 	    if (!tmpsv || !SvOK(tmpsv))					\ 		tmpsv = get_sv(Perl_form(aTHX_ "%s::%s", module,	\ 				    vn = "VERSION"), FALSE);		\ 	}								\ 	if (tmpsv&& (!SvOK(tmpsv) || strNE(XS_VERSION, SvPV(tmpsv, n_a))))	\ 	    Perl_croak(aTHX_ "%s object version %s does not match %s%s%s%s %"SVf,\ 		  module, XS_VERSION,					\ 		  vn ? "$" : "", vn ? module : "", vn ? "::" : "",	\ 		  vn ? vn : "bootstrap parameter", tmpsv);		\     } STMT_END
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XS_VERSION_BOOTCHECK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/* for compatibility */
end_comment

begin_define
define|#
directive|define
name|VTBL_sv
value|&PL_vtbl_sv
end_define

begin_define
define|#
directive|define
name|VTBL_env
value|&PL_vtbl_env
end_define

begin_define
define|#
directive|define
name|VTBL_envelem
value|&PL_vtbl_envelem
end_define

begin_define
define|#
directive|define
name|VTBL_sig
value|&PL_vtbl_sig
end_define

begin_define
define|#
directive|define
name|VTBL_sigelem
value|&PL_vtbl_sigelem
end_define

begin_define
define|#
directive|define
name|VTBL_pack
value|&PL_vtbl_pack
end_define

begin_define
define|#
directive|define
name|VTBL_packelem
value|&PL_vtbl_packelem
end_define

begin_define
define|#
directive|define
name|VTBL_dbline
value|&PL_vtbl_dbline
end_define

begin_define
define|#
directive|define
name|VTBL_isa
value|&PL_vtbl_isa
end_define

begin_define
define|#
directive|define
name|VTBL_isaelem
value|&PL_vtbl_isaelem
end_define

begin_define
define|#
directive|define
name|VTBL_arylen
value|&PL_vtbl_arylen
end_define

begin_define
define|#
directive|define
name|VTBL_glob
value|&PL_vtbl_glob
end_define

begin_define
define|#
directive|define
name|VTBL_mglob
value|&PL_vtbl_mglob
end_define

begin_define
define|#
directive|define
name|VTBL_nkeys
value|&PL_vtbl_nkeys
end_define

begin_define
define|#
directive|define
name|VTBL_taint
value|&PL_vtbl_taint
end_define

begin_define
define|#
directive|define
name|VTBL_substr
value|&PL_vtbl_substr
end_define

begin_define
define|#
directive|define
name|VTBL_vec
value|&PL_vtbl_vec
end_define

begin_define
define|#
directive|define
name|VTBL_pos
value|&PL_vtbl_pos
end_define

begin_define
define|#
directive|define
name|VTBL_bm
value|&PL_vtbl_bm
end_define

begin_define
define|#
directive|define
name|VTBL_fm
value|&PL_vtbl_fm
end_define

begin_define
define|#
directive|define
name|VTBL_uvar
value|&PL_vtbl_uvar
end_define

begin_define
define|#
directive|define
name|VTBL_defelem
value|&PL_vtbl_defelem
end_define

begin_define
define|#
directive|define
name|VTBL_regexp
value|&PL_vtbl_regexp
end_define

begin_define
define|#
directive|define
name|VTBL_regdata
value|&PL_vtbl_regdata
end_define

begin_define
define|#
directive|define
name|VTBL_regdatum
value|&PL_vtbl_regdatum
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LOCALE_COLLATE
end_ifdef

begin_define
define|#
directive|define
name|VTBL_collxfrm
value|&PL_vtbl_collxfrm
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VTBL_amagic
value|&PL_vtbl_amagic
end_define

begin_define
define|#
directive|define
name|VTBL_amagicelem
value|&PL_vtbl_amagicelem
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"perlapi.h"
end_include

begin_include
include|#
directive|include
file|"objXSUB.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PERL_IMPLICIT_CONTEXT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PERL_NO_GET_CONTEXT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PERL_CORE
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|aTHX
end_undef

begin_undef
undef|#
directive|undef
name|aTHX_
end_undef

begin_define
define|#
directive|define
name|aTHX
value|PERL_GET_THX
end_define

begin_define
define|#
directive|define
name|aTHX_
value|aTHX,
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|PERL_CAPI
argument_list|)
operator|||
name|defined
argument_list|(
name|PERL_IMPLICIT_SYS
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|PERL_CORE
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|NO_XSLOCKS
end_ifndef

begin_undef
undef|#
directive|undef
name|closedir
end_undef

begin_undef
undef|#
directive|undef
name|opendir
end_undef

begin_undef
undef|#
directive|undef
name|stdin
end_undef

begin_undef
undef|#
directive|undef
name|stdout
end_undef

begin_undef
undef|#
directive|undef
name|stderr
end_undef

begin_undef
undef|#
directive|undef
name|feof
end_undef

begin_undef
undef|#
directive|undef
name|ferror
end_undef

begin_undef
undef|#
directive|undef
name|fgetpos
end_undef

begin_undef
undef|#
directive|undef
name|ioctl
end_undef

begin_undef
undef|#
directive|undef
name|getlogin
end_undef

begin_undef
undef|#
directive|undef
name|setjmp
end_undef

begin_undef
undef|#
directive|undef
name|getc
end_undef

begin_undef
undef|#
directive|undef
name|ungetc
end_undef

begin_undef
undef|#
directive|undef
name|fileno
end_undef

begin_define
define|#
directive|define
name|mkdir
value|PerlDir_mkdir
end_define

begin_define
define|#
directive|define
name|chdir
value|PerlDir_chdir
end_define

begin_define
define|#
directive|define
name|rmdir
value|PerlDir_rmdir
end_define

begin_define
define|#
directive|define
name|closedir
value|PerlDir_close
end_define

begin_define
define|#
directive|define
name|opendir
value|PerlDir_open
end_define

begin_define
define|#
directive|define
name|readdir
value|PerlDir_read
end_define

begin_define
define|#
directive|define
name|rewinddir
value|PerlDir_rewind
end_define

begin_define
define|#
directive|define
name|seekdir
value|PerlDir_seek
end_define

begin_define
define|#
directive|define
name|telldir
value|PerlDir_tell
end_define

begin_define
define|#
directive|define
name|putenv
value|PerlEnv_putenv
end_define

begin_define
define|#
directive|define
name|getenv
value|PerlEnv_getenv
end_define

begin_define
define|#
directive|define
name|uname
value|PerlEnv_uname
end_define

begin_define
define|#
directive|define
name|stdin
value|PerlIO_stdin()
end_define

begin_define
define|#
directive|define
name|stdout
value|PerlIO_stdout()
end_define

begin_define
define|#
directive|define
name|stderr
value|PerlIO_stderr()
end_define

begin_define
define|#
directive|define
name|fopen
value|PerlIO_open
end_define

begin_define
define|#
directive|define
name|fclose
value|PerlIO_close
end_define

begin_define
define|#
directive|define
name|feof
value|PerlIO_eof
end_define

begin_define
define|#
directive|define
name|ferror
value|PerlIO_error
end_define

begin_define
define|#
directive|define
name|fclearerr
value|PerlIO_clearerr
end_define

begin_define
define|#
directive|define
name|getc
value|PerlIO_getc
end_define

begin_define
define|#
directive|define
name|fputc
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|PerlIO_putc(f,c)
end_define

begin_define
define|#
directive|define
name|fputs
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|PerlIO_puts(f,s)
end_define

begin_define
define|#
directive|define
name|fflush
value|PerlIO_flush
end_define

begin_define
define|#
directive|define
name|ungetc
parameter_list|(
name|c
parameter_list|,
name|f
parameter_list|)
value|PerlIO_ungetc((f),(c))
end_define

begin_define
define|#
directive|define
name|fileno
value|PerlIO_fileno
end_define

begin_define
define|#
directive|define
name|fdopen
value|PerlIO_fdopen
end_define

begin_define
define|#
directive|define
name|freopen
value|PerlIO_reopen
end_define

begin_define
define|#
directive|define
name|fread
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|,
name|f
parameter_list|)
value|PerlIO_read((f),(b),(s*c))
end_define

begin_define
define|#
directive|define
name|fwrite
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|,
name|f
parameter_list|)
value|PerlIO_write((f),(b),(s*c))
end_define

begin_define
define|#
directive|define
name|setbuf
value|PerlIO_setbuf
end_define

begin_define
define|#
directive|define
name|setvbuf
value|PerlIO_setvbuf
end_define

begin_define
define|#
directive|define
name|setlinebuf
value|PerlIO_setlinebuf
end_define

begin_define
define|#
directive|define
name|stdoutf
value|PerlIO_stdoutf
end_define

begin_define
define|#
directive|define
name|vfprintf
value|PerlIO_vprintf
end_define

begin_define
define|#
directive|define
name|ftell
value|PerlIO_tell
end_define

begin_define
define|#
directive|define
name|fseek
value|PerlIO_seek
end_define

begin_define
define|#
directive|define
name|fgetpos
value|PerlIO_getpos
end_define

begin_define
define|#
directive|define
name|fsetpos
value|PerlIO_setpos
end_define

begin_define
define|#
directive|define
name|frewind
value|PerlIO_rewind
end_define

begin_define
define|#
directive|define
name|tmpfile
value|PerlIO_tmpfile
end_define

begin_define
define|#
directive|define
name|access
value|PerlLIO_access
end_define

begin_define
define|#
directive|define
name|chmod
value|PerlLIO_chmod
end_define

begin_define
define|#
directive|define
name|chsize
value|PerlLIO_chsize
end_define

begin_define
define|#
directive|define
name|close
value|PerlLIO_close
end_define

begin_define
define|#
directive|define
name|dup
value|PerlLIO_dup
end_define

begin_define
define|#
directive|define
name|dup2
value|PerlLIO_dup2
end_define

begin_define
define|#
directive|define
name|flock
value|PerlLIO_flock
end_define

begin_define
define|#
directive|define
name|fstat
value|PerlLIO_fstat
end_define

begin_define
define|#
directive|define
name|ioctl
value|PerlLIO_ioctl
end_define

begin_define
define|#
directive|define
name|isatty
value|PerlLIO_isatty
end_define

begin_define
define|#
directive|define
name|link
value|PerlLIO_link
end_define

begin_define
define|#
directive|define
name|lseek
value|PerlLIO_lseek
end_define

begin_define
define|#
directive|define
name|lstat
value|PerlLIO_lstat
end_define

begin_define
define|#
directive|define
name|mktemp
value|PerlLIO_mktemp
end_define

begin_define
define|#
directive|define
name|open
value|PerlLIO_open
end_define

begin_define
define|#
directive|define
name|read
value|PerlLIO_read
end_define

begin_define
define|#
directive|define
name|rename
value|PerlLIO_rename
end_define

begin_define
define|#
directive|define
name|setmode
value|PerlLIO_setmode
end_define

begin_define
define|#
directive|define
name|stat
parameter_list|(
name|buf
parameter_list|,
name|sb
parameter_list|)
value|PerlLIO_stat(buf,sb)
end_define

begin_define
define|#
directive|define
name|tmpnam
value|PerlLIO_tmpnam
end_define

begin_define
define|#
directive|define
name|umask
value|PerlLIO_umask
end_define

begin_define
define|#
directive|define
name|unlink
value|PerlLIO_unlink
end_define

begin_define
define|#
directive|define
name|utime
value|PerlLIO_utime
end_define

begin_define
define|#
directive|define
name|write
value|PerlLIO_write
end_define

begin_define
define|#
directive|define
name|malloc
value|PerlMem_malloc
end_define

begin_define
define|#
directive|define
name|realloc
value|PerlMem_realloc
end_define

begin_define
define|#
directive|define
name|free
value|PerlMem_free
end_define

begin_define
define|#
directive|define
name|abort
value|PerlProc_abort
end_define

begin_define
define|#
directive|define
name|exit
value|PerlProc_exit
end_define

begin_define
define|#
directive|define
name|_exit
value|PerlProc__exit
end_define

begin_define
define|#
directive|define
name|execl
value|PerlProc_execl
end_define

begin_define
define|#
directive|define
name|execv
value|PerlProc_execv
end_define

begin_define
define|#
directive|define
name|execvp
value|PerlProc_execvp
end_define

begin_define
define|#
directive|define
name|getuid
value|PerlProc_getuid
end_define

begin_define
define|#
directive|define
name|geteuid
value|PerlProc_geteuid
end_define

begin_define
define|#
directive|define
name|getgid
value|PerlProc_getgid
end_define

begin_define
define|#
directive|define
name|getegid
value|PerlProc_getegid
end_define

begin_define
define|#
directive|define
name|getlogin
value|PerlProc_getlogin
end_define

begin_define
define|#
directive|define
name|kill
value|PerlProc_kill
end_define

begin_define
define|#
directive|define
name|killpg
value|PerlProc_killpg
end_define

begin_define
define|#
directive|define
name|pause
value|PerlProc_pause
end_define

begin_define
define|#
directive|define
name|popen
value|PerlProc_popen
end_define

begin_define
define|#
directive|define
name|pclose
value|PerlProc_pclose
end_define

begin_define
define|#
directive|define
name|pipe
value|PerlProc_pipe
end_define

begin_define
define|#
directive|define
name|setuid
value|PerlProc_setuid
end_define

begin_define
define|#
directive|define
name|setgid
value|PerlProc_setgid
end_define

begin_define
define|#
directive|define
name|sleep
value|PerlProc_sleep
end_define

begin_define
define|#
directive|define
name|times
value|PerlProc_times
end_define

begin_define
define|#
directive|define
name|wait
value|PerlProc_wait
end_define

begin_define
define|#
directive|define
name|setjmp
value|PerlProc_setjmp
end_define

begin_define
define|#
directive|define
name|longjmp
value|PerlProc_longjmp
end_define

begin_define
define|#
directive|define
name|signal
value|PerlProc_signal
end_define

begin_define
define|#
directive|define
name|getpid
value|PerlProc_getpid
end_define

begin_define
define|#
directive|define
name|htonl
value|PerlSock_htonl
end_define

begin_define
define|#
directive|define
name|htons
value|PerlSock_htons
end_define

begin_define
define|#
directive|define
name|ntohl
value|PerlSock_ntohl
end_define

begin_define
define|#
directive|define
name|ntohs
value|PerlSock_ntohs
end_define

begin_define
define|#
directive|define
name|accept
value|PerlSock_accept
end_define

begin_define
define|#
directive|define
name|bind
value|PerlSock_bind
end_define

begin_define
define|#
directive|define
name|connect
value|PerlSock_connect
end_define

begin_define
define|#
directive|define
name|endhostent
value|PerlSock_endhostent
end_define

begin_define
define|#
directive|define
name|endnetent
value|PerlSock_endnetent
end_define

begin_define
define|#
directive|define
name|endprotoent
value|PerlSock_endprotoent
end_define

begin_define
define|#
directive|define
name|endservent
value|PerlSock_endservent
end_define

begin_define
define|#
directive|define
name|gethostbyaddr
value|PerlSock_gethostbyaddr
end_define

begin_define
define|#
directive|define
name|gethostbyname
value|PerlSock_gethostbyname
end_define

begin_define
define|#
directive|define
name|gethostent
value|PerlSock_gethostent
end_define

begin_define
define|#
directive|define
name|gethostname
value|PerlSock_gethostname
end_define

begin_define
define|#
directive|define
name|getnetbyaddr
value|PerlSock_getnetbyaddr
end_define

begin_define
define|#
directive|define
name|getnetbyname
value|PerlSock_getnetbyname
end_define

begin_define
define|#
directive|define
name|getnetent
value|PerlSock_getnetent
end_define

begin_define
define|#
directive|define
name|getpeername
value|PerlSock_getpeername
end_define

begin_define
define|#
directive|define
name|getprotobyname
value|PerlSock_getprotobyname
end_define

begin_define
define|#
directive|define
name|getprotobynumber
value|PerlSock_getprotobynumber
end_define

begin_define
define|#
directive|define
name|getprotoent
value|PerlSock_getprotoent
end_define

begin_define
define|#
directive|define
name|getservbyname
value|PerlSock_getservbyname
end_define

begin_define
define|#
directive|define
name|getservbyport
value|PerlSock_getservbyport
end_define

begin_define
define|#
directive|define
name|getservent
value|PerlSock_getservent
end_define

begin_define
define|#
directive|define
name|getsockname
value|PerlSock_getsockname
end_define

begin_define
define|#
directive|define
name|getsockopt
value|PerlSock_getsockopt
end_define

begin_define
define|#
directive|define
name|inet_addr
value|PerlSock_inet_addr
end_define

begin_define
define|#
directive|define
name|inet_ntoa
value|PerlSock_inet_ntoa
end_define

begin_define
define|#
directive|define
name|listen
value|PerlSock_listen
end_define

begin_define
define|#
directive|define
name|recv
value|PerlSock_recv
end_define

begin_define
define|#
directive|define
name|recvfrom
value|PerlSock_recvfrom
end_define

begin_define
define|#
directive|define
name|select
value|PerlSock_select
end_define

begin_define
define|#
directive|define
name|send
value|PerlSock_send
end_define

begin_define
define|#
directive|define
name|sendto
value|PerlSock_sendto
end_define

begin_define
define|#
directive|define
name|sethostent
value|PerlSock_sethostent
end_define

begin_define
define|#
directive|define
name|setnetent
value|PerlSock_setnetent
end_define

begin_define
define|#
directive|define
name|setprotoent
value|PerlSock_setprotoent
end_define

begin_define
define|#
directive|define
name|setservent
value|PerlSock_setservent
end_define

begin_define
define|#
directive|define
name|setsockopt
value|PerlSock_setsockopt
end_define

begin_define
define|#
directive|define
name|shutdown
value|PerlSock_shutdown
end_define

begin_define
define|#
directive|define
name|socket
value|PerlSock_socket
end_define

begin_define
define|#
directive|define
name|socketpair
value|PerlSock_socketpair
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_XSLOCKS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_CAPI */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _INC_PERL_XSUB_H */
end_comment

begin_comment
comment|/* include guard */
end_comment

end_unit

