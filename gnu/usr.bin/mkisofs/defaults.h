begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header file defaults.h - assorted default values for character strings in  * the volume descriptor.  */
end_comment

begin_define
define|#
directive|define
name|PREPARER_DEFAULT
value|NULL
end_define

begin_define
define|#
directive|define
name|PUBLISHER_DEFAULT
value|NULL
end_define

begin_define
define|#
directive|define
name|APPID_DEFAULT
value|NULL
end_define

begin_define
define|#
directive|define
name|COPYRIGHT_DEFAULT
value|NULL
end_define

begin_define
define|#
directive|define
name|BIBLIO_DEFAULT
value|NULL
end_define

begin_define
define|#
directive|define
name|ABSTRACT_DEFAULT
value|NULL
end_define

begin_define
define|#
directive|define
name|VOLSET_ID_DEFAULT
value|NULL
end_define

begin_define
define|#
directive|define
name|VOLUME_ID_DEFAULT
value|"CDROM"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM_ID_DEFAULT
value|"FreeBSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__QNX__
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM_ID_DEFAULT
value|"QNX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM_ID_DEFAULT
value|"LINUX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__osf__
end_ifdef

begin_define
define|#
directive|define
name|SYSTEM_ID_DEFAULT
value|"OSF"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SYSTEM_ID_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|SYSTEM_ID_DEFAULT
value|"UNKNOWNSYS"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

