begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|Incremental_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Incremental_h
end_define

begin_define
define|#
directive|define
name|DECLARE_INIT_FUNCTION
parameter_list|(
name|USER_INIT_FUNCTION
parameter_list|)
define|\
value|static void USER_INIT_FUNCTION (); extern void (*_initfn)(); \ static struct xyzzy { xyzzy () {_initfn = USER_INIT_FUNCTION;}; \ ~xyzzy () {};} __2xyzzy;
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Incremental.h was not the first file included in this module
end_error

begin_endif
endif|#
directive|endif
end_endif

end_unit

