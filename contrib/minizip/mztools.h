begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   Additional tools for Minizip   Code: Xavier Roche '2004   License: Same as ZLIB (www.gzip.org) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_zip_tools_H
end_ifndef

begin_define
define|#
directive|define
name|_zip_tools_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifndef|#
directive|ifndef
name|_ZLIB_H
include|#
directive|include
file|"zlib.h"
endif|#
directive|endif
include|#
directive|include
file|"unzip.h"
comment|/* Repair a ZIP file (missing central directory)    file: file to recover    fileOut: output file after recovery    fileOutTmp: temporary file name used for recovery */
specifier|extern
name|int
name|ZEXPORT
name|unzRepair
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
specifier|const
name|char
modifier|*
name|fileOut
parameter_list|,
specifier|const
name|char
modifier|*
name|fileOutTmp
parameter_list|,
name|uLong
modifier|*
name|nRecovered
parameter_list|,
name|uLong
modifier|*
name|bytesRecovered
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

