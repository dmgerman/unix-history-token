begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /f/osi/others/quipu/uips/pod/RCS/defs.h,v 7.1 91/02/22 09:31:28 mrose Interim $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PODDEFS
end_ifndef

begin_define
define|#
directive|define
name|PODDEFS
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULLCP
end_ifndef

begin_define
define|#
directive|define
name|NULLCP
value|(char *) 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|short
name|bool
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|rfc822
block|,
name|greybook
block|}
name|mailtype
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|Okay
block|,
name|timelimit
block|,
name|timelimit_w_partial
block|,
name|listsizelimit
block|,
name|adminlimit
block|,
name|adminlimit_w_partial
block|,
name|nothingfound
block|,
name|localdsaerror
block|,
name|remotedsaerror
block|,
name|duaerror
block|,
name|attributerror
block|,
name|namerror
block|,
name|security
block|,
name|updaterror
block|,
name|serviceerror
block|}
name|dsEnqError
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dsErrorStruct
block|{
name|dsEnqError
name|error
decl_stmt|;
name|char
modifier|*
name|err_mess
decl_stmt|;
block|}
name|dsErrorStruct
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RESBUF
value|10000
end_define

begin_define
define|#
directive|define
name|MAXARGS
value|20
end_define

begin_define
define|#
directive|define
name|STRINGLEN
value|1000
end_define

begin_define
define|#
directive|define
name|SMALLSTRING
value|255
end_define

begin_define
define|#
directive|define
name|MAXTYPES
value|255
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

