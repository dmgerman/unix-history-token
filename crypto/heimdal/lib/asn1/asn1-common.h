begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: asn1-common.h,v 1.1 2000/04/14 15:41:31 joda Exp $ */
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__asn1_common_definitions__
end_ifndef

begin_define
define|#
directive|define
name|__asn1_common_definitions__
end_define

begin_typedef
typedef|typedef
struct|struct
name|octet_string
block|{
name|size_t
name|length
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
block|}
name|octet_string
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|general_string
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

