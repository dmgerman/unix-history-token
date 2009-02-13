begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIZEOF_INT
end_ifdef

begin_undef
undef|#
directive|undef
name|SIZEOF_INT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIZEOF_SHORT
end_ifdef

begin_undef
undef|#
directive|undef
name|SIZEOF_SHORT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIZEOF_LONG
end_ifdef

begin_undef
undef|#
directive|undef
name|SIZEOF_LONG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIZEOF_VOID_P
end_ifdef

begin_undef
undef|#
directive|undef
name|SIZEOF_VOID_P
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SIZEOF_LONG_LONG
end_ifdef

begin_undef
undef|#
directive|undef
name|SIZEOF_LONG_LONG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_WIDE_INT
end_ifdef

begin_undef
undef|#
directive|undef
name|HOST_WIDE_INT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIZEOF_INT
value|4
end_define

begin_define
define|#
directive|define
name|SIZEOF_SHORT
value|2
end_define

begin_define
define|#
directive|define
name|SIZEOF_LONG_LONG
value|8
end_define

begin_if
if|#
directive|if
name|__LP64__
end_if

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|8
end_define

begin_define
define|#
directive|define
name|SIZEOF_VOID_P
value|8
end_define

begin_define
define|#
directive|define
name|HOST_WIDE_INT
value|long
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|4
end_define

begin_define
define|#
directive|define
name|SIZEOF_VOID_P
value|4
end_define

begin_define
define|#
directive|define
name|HOST_WIDE_INT
value|long long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
end_ifdef

begin_undef
undef|#
directive|undef
name|WORDS_BIGENDIAN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sparc64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARMEB__
argument_list|)
end_if

begin_define
define|#
directive|define
name|WORDS_BIGENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

