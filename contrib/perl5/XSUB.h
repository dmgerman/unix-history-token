begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|ST
parameter_list|(
name|off
parameter_list|)
value|PL_stack_base[ax + (off)]
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CAN_PROTOTYPE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_OBJECT
end_ifdef

begin_define
define|#
directive|define
name|XS
parameter_list|(
name|name
parameter_list|)
value|void name(CV* cv, CPerlObj* pPerl)
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
value|void name(CV* cv)
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
name|XS
parameter_list|(
name|name
parameter_list|)
value|void name(cv) CV* cv;
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
value|((XSINTERFACE_CVT(ret,))(f))
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
value|CvXSUBANY(cv).any_dptr = (void (*) _((void*)))(f)
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

begin_comment
comment|/* Simple macros to put new mortal values onto the stack.   */
end_comment

begin_comment
comment|/* Typically used to return values from XS functions.       */
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
value|\ 	    tmpsv = perl_get_sv(form("%s::%s", module,			\ 				  vn = "XS_VERSION"), FALSE);		\ 	    if (!tmpsv || !SvOK(tmpsv))					\ 		tmpsv = perl_get_sv(form("%s::%s", module,		\ 				      vn = "VERSION"), FALSE);		\ 	}								\ 	if (tmpsv&& (!SvOK(tmpsv) || strNE(XS_VERSION, SvPV(tmpsv, n_a))))	\ 	    croak("%s object version %s does not match %s%s%s%s %_",	\ 		  module, XS_VERSION,					\ 		  vn ? "$" : "", vn ? module : "", vn ? "::" : "",	\ 		  vn ? vn : "bootstrap parameter", tmpsv);		\     } STMT_END
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

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_CAPI
end_ifdef

begin_define
define|#
directive|define
name|VTBL_sv
value|get_vtbl(want_vtbl_sv)
end_define

begin_define
define|#
directive|define
name|VTBL_env
value|get_vtbl(want_vtbl_env)
end_define

begin_define
define|#
directive|define
name|VTBL_envelem
value|get_vtbl(want_vtbl_envelem)
end_define

begin_define
define|#
directive|define
name|VTBL_sig
value|get_vtbl(want_vtbl_sig)
end_define

begin_define
define|#
directive|define
name|VTBL_sigelem
value|get_vtbl(want_vtbl_sigelem)
end_define

begin_define
define|#
directive|define
name|VTBL_pack
value|get_vtbl(want_vtbl_pack)
end_define

begin_define
define|#
directive|define
name|VTBL_packelem
value|get_vtbl(want_vtbl_packelem)
end_define

begin_define
define|#
directive|define
name|VTBL_dbline
value|get_vtbl(want_vtbl_dbline)
end_define

begin_define
define|#
directive|define
name|VTBL_isa
value|get_vtbl(want_vtbl_isa)
end_define

begin_define
define|#
directive|define
name|VTBL_isaelem
value|get_vtbl(want_vtbl_isaelem)
end_define

begin_define
define|#
directive|define
name|VTBL_arylen
value|get_vtbl(want_vtbl_arylen)
end_define

begin_define
define|#
directive|define
name|VTBL_glob
value|get_vtbl(want_vtbl_glob)
end_define

begin_define
define|#
directive|define
name|VTBL_mglob
value|get_vtbl(want_vtbl_mglob)
end_define

begin_define
define|#
directive|define
name|VTBL_nkeys
value|get_vtbl(want_vtbl_nkeys)
end_define

begin_define
define|#
directive|define
name|VTBL_taint
value|get_vtbl(want_vtbl_taint)
end_define

begin_define
define|#
directive|define
name|VTBL_substr
value|get_vtbl(want_vtbl_substr)
end_define

begin_define
define|#
directive|define
name|VTBL_vec
value|get_vtbl(want_vtbl_vec)
end_define

begin_define
define|#
directive|define
name|VTBL_pos
value|get_vtbl(want_vtbl_pos)
end_define

begin_define
define|#
directive|define
name|VTBL_bm
value|get_vtbl(want_vtbl_bm)
end_define

begin_define
define|#
directive|define
name|VTBL_fm
value|get_vtbl(want_vtbl_fm)
end_define

begin_define
define|#
directive|define
name|VTBL_uvar
value|get_vtbl(want_vtbl_uvar)
end_define

begin_define
define|#
directive|define
name|VTBL_defelem
value|get_vtbl(want_vtbl_defelem)
end_define

begin_define
define|#
directive|define
name|VTBL_regexp
value|get_vtbl(want_vtbl_regexp)
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
value|get_vtbl(want_vtbl_collxfrm)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OVERLOAD
end_ifdef

begin_define
define|#
directive|define
name|VTBL_amagic
value|get_vtbl(want_vtbl_amagic)
end_define

begin_define
define|#
directive|define
name|VTBL_amagicelem
value|get_vtbl(want_vtbl_amagicelem)
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
name|VTBL_sv
value|&vtbl_sv
end_define

begin_define
define|#
directive|define
name|VTBL_env
value|&vtbl_env
end_define

begin_define
define|#
directive|define
name|VTBL_envelem
value|&vtbl_envelem
end_define

begin_define
define|#
directive|define
name|VTBL_sig
value|&vtbl_sig
end_define

begin_define
define|#
directive|define
name|VTBL_sigelem
value|&vtbl_sigelem
end_define

begin_define
define|#
directive|define
name|VTBL_pack
value|&vtbl_pack
end_define

begin_define
define|#
directive|define
name|VTBL_packelem
value|&vtbl_packelem
end_define

begin_define
define|#
directive|define
name|VTBL_dbline
value|&vtbl_dbline
end_define

begin_define
define|#
directive|define
name|VTBL_isa
value|&vtbl_isa
end_define

begin_define
define|#
directive|define
name|VTBL_isaelem
value|&vtbl_isaelem
end_define

begin_define
define|#
directive|define
name|VTBL_arylen
value|&vtbl_arylen
end_define

begin_define
define|#
directive|define
name|VTBL_glob
value|&vtbl_glob
end_define

begin_define
define|#
directive|define
name|VTBL_mglob
value|&vtbl_mglob
end_define

begin_define
define|#
directive|define
name|VTBL_nkeys
value|&vtbl_nkeys
end_define

begin_define
define|#
directive|define
name|VTBL_taint
value|&vtbl_taint
end_define

begin_define
define|#
directive|define
name|VTBL_substr
value|&vtbl_substr
end_define

begin_define
define|#
directive|define
name|VTBL_vec
value|&vtbl_vec
end_define

begin_define
define|#
directive|define
name|VTBL_pos
value|&vtbl_pos
end_define

begin_define
define|#
directive|define
name|VTBL_bm
value|&vtbl_bm
end_define

begin_define
define|#
directive|define
name|VTBL_fm
value|&vtbl_fm
end_define

begin_define
define|#
directive|define
name|VTBL_uvar
value|&vtbl_uvar
end_define

begin_define
define|#
directive|define
name|VTBL_defelem
value|&vtbl_defelem
end_define

begin_define
define|#
directive|define
name|VTBL_regexp
value|&vtbl_regexp
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
value|&vtbl_collxfrm
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OVERLOAD
end_ifdef

begin_define
define|#
directive|define
name|VTBL_amagic
value|&vtbl_amagic
end_define

begin_define
define|#
directive|define
name|VTBL_amagicelem
value|&vtbl_amagicelem
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
name|PERL_OBJECT
end_ifdef

begin_include
include|#
directive|include
file|"objXSUB.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NO_XSLOCKS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_include
include|#
directive|include
file|"XSlock.h"
end_include

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
comment|/* NO_XSLOCKS */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|PERL_CAPI
end_ifdef

begin_include
include|#
directive|include
file|"perlCAPI.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PERL_OBJECT */
end_comment

end_unit

