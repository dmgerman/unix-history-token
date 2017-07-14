begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * Copyright (c) 2016-present, Yann Collet, Facebook, Inc.  * All rights reserved.  *  * This source code is licensed under the BSD-style license found in the  * LICENSE file in the root directory of this source tree. An additional grant  * of patent rights can be found in the PATENTS file in the same directory.  */
end_comment

begin_comment
comment|/* The purpose of this file is to have a single list of error strings embedded in binary */
end_comment

begin_include
include|#
directive|include
file|"error_private.h"
end_include

begin_function
specifier|const
name|char
modifier|*
name|ERR_getErrorString
parameter_list|(
name|ERR_enum
name|code
parameter_list|)
block|{
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|notErrorCode
init|=
literal|"Unspecified error code"
decl_stmt|;
switch|switch
condition|(
name|code
condition|)
block|{
case|case
name|PREFIX
argument_list|(
name|no_error
argument_list|)
case|:
return|return
literal|"No error detected"
return|;
case|case
name|PREFIX
argument_list|(
name|GENERIC
argument_list|)
case|:
return|return
literal|"Error (generic)"
return|;
case|case
name|PREFIX
argument_list|(
name|prefix_unknown
argument_list|)
case|:
return|return
literal|"Unknown frame descriptor"
return|;
case|case
name|PREFIX
argument_list|(
name|version_unsupported
argument_list|)
case|:
return|return
literal|"Version not supported"
return|;
case|case
name|PREFIX
argument_list|(
name|parameter_unknown
argument_list|)
case|:
return|return
literal|"Unknown parameter type"
return|;
case|case
name|PREFIX
argument_list|(
name|frameParameter_unsupported
argument_list|)
case|:
return|return
literal|"Unsupported frame parameter"
return|;
case|case
name|PREFIX
argument_list|(
name|frameParameter_unsupportedBy32bits
argument_list|)
case|:
return|return
literal|"Frame parameter unsupported in 32-bits mode"
return|;
case|case
name|PREFIX
argument_list|(
name|frameParameter_windowTooLarge
argument_list|)
case|:
return|return
literal|"Frame requires too much memory for decoding"
return|;
case|case
name|PREFIX
argument_list|(
name|compressionParameter_unsupported
argument_list|)
case|:
return|return
literal|"Compression parameter is not supported"
return|;
case|case
name|PREFIX
argument_list|(
name|compressionParameter_outOfBound
argument_list|)
case|:
return|return
literal|"Compression parameter is out of bound"
return|;
case|case
name|PREFIX
argument_list|(
name|init_missing
argument_list|)
case|:
return|return
literal|"Context should be init first"
return|;
case|case
name|PREFIX
argument_list|(
name|memory_allocation
argument_list|)
case|:
return|return
literal|"Allocation error : not enough memory"
return|;
case|case
name|PREFIX
argument_list|(
name|stage_wrong
argument_list|)
case|:
return|return
literal|"Operation not authorized at current processing stage"
return|;
case|case
name|PREFIX
argument_list|(
name|dstSize_tooSmall
argument_list|)
case|:
return|return
literal|"Destination buffer is too small"
return|;
case|case
name|PREFIX
argument_list|(
name|srcSize_wrong
argument_list|)
case|:
return|return
literal|"Src size is incorrect"
return|;
case|case
name|PREFIX
argument_list|(
name|corruption_detected
argument_list|)
case|:
return|return
literal|"Corrupted block detected"
return|;
case|case
name|PREFIX
argument_list|(
name|checksum_wrong
argument_list|)
case|:
return|return
literal|"Restored data doesn't match checksum"
return|;
case|case
name|PREFIX
argument_list|(
name|tableLog_tooLarge
argument_list|)
case|:
return|return
literal|"tableLog requires too much memory : unsupported"
return|;
case|case
name|PREFIX
argument_list|(
name|maxSymbolValue_tooLarge
argument_list|)
case|:
return|return
literal|"Unsupported max Symbol Value : too large"
return|;
case|case
name|PREFIX
argument_list|(
name|maxSymbolValue_tooSmall
argument_list|)
case|:
return|return
literal|"Specified maxSymbolValue is too small"
return|;
case|case
name|PREFIX
argument_list|(
name|dictionary_corrupted
argument_list|)
case|:
return|return
literal|"Dictionary is corrupted"
return|;
case|case
name|PREFIX
argument_list|(
name|dictionary_wrong
argument_list|)
case|:
return|return
literal|"Dictionary mismatch"
return|;
case|case
name|PREFIX
argument_list|(
name|dictionaryCreation_failed
argument_list|)
case|:
return|return
literal|"Cannot create Dictionary from provided samples"
return|;
case|case
name|PREFIX
argument_list|(
name|frameIndex_tooLarge
argument_list|)
case|:
return|return
literal|"Frame index is too large"
return|;
case|case
name|PREFIX
argument_list|(
name|seekableIO
argument_list|)
case|:
return|return
literal|"An I/O error occurred when reading/seeking"
return|;
case|case
name|PREFIX
argument_list|(
name|maxCode
argument_list|)
case|:
default|default:
return|return
name|notErrorCode
return|;
block|}
block|}
end_function

end_unit

