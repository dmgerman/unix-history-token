begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* maxpath.h - Find out what this system thinks MAXPATHLEN is. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MAXPATH_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|_MAXPATH_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|isc386
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BUILDING_MAKEFILE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAXPATHLEN
argument_list|)
operator|&&
name|defined
argument_list|(
name|PATH_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAXPATHLEN
value|PATH_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MAXPATHLEN&& PATH_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* isc386&& BUILDING_MAKEFILE */
end_comment

begin_comment
comment|/* Yecch!  Who cares about this gross concept in the first place? */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAXPATHLEN
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAXPATHLEN
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAXPATHLEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAXPATH_H */
end_comment

end_unit

