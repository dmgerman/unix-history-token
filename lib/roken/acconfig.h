begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_expr_stmt
unit|@
name|BOTTOM
expr|@
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BROKEN_REALLOC
end_ifdef

begin_define
define|#
directive|define
name|realloc
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|isoc_realloc((X), (Y))
end_define

begin_define
define|#
directive|define
name|isoc_realloc
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|((X) ? realloc((X), (Y)) : malloc(Y))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VOID_RETSIGTYPE
end_ifdef

begin_define
define|#
directive|define
name|SIGRETURN
parameter_list|(
name|x
parameter_list|)
value|return
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGRETURN
parameter_list|(
name|x
parameter_list|)
value|return (RETSIGTYPE)(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|msg
parameter_list|)
define|\
value|static
comment|/**/
value|const char *const rcsid[] = { (const char *)rcsid, "\100(#)" msg }
end_define

begin_undef
undef|#
directive|undef
name|PROTOTYPES
end_undef

begin_comment
comment|/* Maximum values on all known systems */
end_comment

begin_define
define|#
directive|define
name|MaxHostNameLen
value|(64+4)
end_define

begin_define
define|#
directive|define
name|MaxPathLen
value|(1024+4)
end_define

begin_comment
comment|/*  * Define NDBM if you are using the 4.3 ndbm library (which is part of  * libc).  If not defined, 4.2 dbm will be assumed.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_DBM_FIRSTKEY
argument_list|)
end_if

begin_define
define|#
directive|define
name|NDBM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Defining this enables lots of useful (and used) extensions on  * glibc-based systems such as Linux  */
end_comment

begin_define
define|#
directive|define
name|_GNU_SOURCE
end_define

end_unit

