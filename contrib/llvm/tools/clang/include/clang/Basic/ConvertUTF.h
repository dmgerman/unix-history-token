begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===--- ConvertUTF.h - Universal Character Names conversions ---------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is distributed under the University of Illinois Open Source  * License. See LICENSE.TXT for details.  *  *==------------------------------------------------------------------------==*/
end_comment

begin_comment
comment|/*  * Copyright 2001-2004 Unicode, Inc.  *  * Disclaimer  *  * This source code is provided as is by Unicode, Inc. No claims are  * made as to fitness for any particular purpose. No warranties of any  * kind are expressed or implied. The recipient agrees to determine  * applicability of information provided. If this file has been  * purchased on magnetic or optical media from Unicode, Inc., the  * sole remedy for any claim will be exchange of defective media  * within 90 days of receipt.  *  * Limitations on Rights to Redistribute This Code  *  * Unicode, Inc. hereby grants the right to freely use the information  * supplied in this file in the creation of products supporting the  * Unicode Standard, and to make copies of this file in any form  * for internal or external distribution as long as this notice  * remains attached.  */
end_comment

begin_comment
comment|/* ---------------------------------------------------------------------      Conversions between UTF32, UTF-16, and UTF-8.  Header file.      Several funtions are included here, forming a complete set of     conversions between the three formats.  UTF-7 is not included     here, but is handled in a separate source file.      Each of these routines takes pointers to input buffers and output     buffers.  The input buffers are const.      Each routine converts the text between *sourceStart and sourceEnd,     putting the result into the buffer between *targetStart and     targetEnd. Note: the end pointers are *after* the last item: e.g.     *(sourceEnd - 1) is the last item.      The return result indicates whether the conversion was successful,     and if not, whether the problem was in the source or target buffers.     (Only the first encountered problem is indicated.)      After the conversion, *sourceStart and *targetStart are both     updated to point to the end of last text successfully converted in     the respective buffers.      Input parameters:         sourceStart - pointer to a pointer to the source buffer.                 The contents of this are modified on return so that                 it points at the next thing to be converted.         targetStart - similarly, pointer to pointer to the target buffer.         sourceEnd, targetEnd - respectively pointers to the ends of the                 two buffers, for overflow checking only.      These conversion functions take a ConversionFlags argument. When this     flag is set to strict, both irregular sequences and isolated surrogates     will cause an error.  When the flag is set to lenient, both irregular     sequences and isolated surrogates are converted.      Whether the flag is strict or lenient, all illegal sequences will cause     an error return. This includes sequences such as:<F4 90 80 80>,<C0 80>,     or<A0> in UTF-8, and values above 0x10FFFF in UTF-32. Conformant code     must check for illegal sequences.      When the flag is set to lenient, characters over 0x10FFFF are converted     to the replacement character; otherwise (when the flag is set to strict)     they constitute an error.      Output parameters:         The value "sourceIllegal" is returned from some routines if the input         sequence is malformed.  When "sourceIllegal" is returned, the source         value will point to the illegal value that caused the problem. E.g.,         in UTF-8 when a sequence is malformed, it points to the start of the         malformed sequence.      Author: Mark E. Davis, 1994.     Rev History: Rick McGowan, fixes& updates May 2001.          Fixes& updates, Sept 2001.  ------------------------------------------------------------------------ */
end_comment

begin_comment
comment|/* ---------------------------------------------------------------------     The following 4 definitions are compiler-specific.     The C standard does not guarantee that wchar_t has at least     16 bits, so wchar_t is no less portable than unsigned short!     All should be unsigned values to avoid sign extension during     bit mask& shift operations. ------------------------------------------------------------------------ */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|UTF32
typedef|;
end_typedef

begin_comment
comment|/* at least 32 bits */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|UTF16
typedef|;
end_typedef

begin_comment
comment|/* at least 16 bits */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UTF8
typedef|;
end_typedef

begin_comment
comment|/* typically 8 bits */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Boolean
typedef|;
end_typedef

begin_comment
comment|/* 0 or 1 */
end_comment

begin_comment
comment|/* Some fundamental constants */
end_comment

begin_define
define|#
directive|define
name|UNI_REPLACEMENT_CHAR
value|(UTF32)0x0000FFFD
end_define

begin_define
define|#
directive|define
name|UNI_MAX_BMP
value|(UTF32)0x0000FFFF
end_define

begin_define
define|#
directive|define
name|UNI_MAX_UTF16
value|(UTF32)0x0010FFFF
end_define

begin_define
define|#
directive|define
name|UNI_MAX_UTF32
value|(UTF32)0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|UNI_MAX_LEGAL_UTF32
value|(UTF32)0x0010FFFF
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|conversionOK
block|,
comment|/* conversion successful */
name|sourceExhausted
block|,
comment|/* partial character in source, but hit end */
name|targetExhausted
block|,
comment|/* insuff. room in target for conversion */
name|sourceIllegal
comment|/* source sequence is illegal/malformed */
block|}
name|ConversionResult
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|strictConversion
init|=
literal|0
block|,
name|lenientConversion
block|}
name|ConversionFlags
typedef|;
end_typedef

begin_comment
comment|/* This is for C++ and does no harm in C */
end_comment

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
name|ConversionResult
name|ConvertUTF8toUTF16
parameter_list|(
specifier|const
name|UTF8
modifier|*
modifier|*
name|sourceStart
parameter_list|,
specifier|const
name|UTF8
modifier|*
name|sourceEnd
parameter_list|,
name|UTF16
modifier|*
modifier|*
name|targetStart
parameter_list|,
name|UTF16
modifier|*
name|targetEnd
parameter_list|,
name|ConversionFlags
name|flags
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|CLANG_NEEDS_THESE_ONE_DAY
name|ConversionResult
name|ConvertUTF16toUTF8
parameter_list|(
specifier|const
name|UTF16
modifier|*
modifier|*
name|sourceStart
parameter_list|,
specifier|const
name|UTF16
modifier|*
name|sourceEnd
parameter_list|,
name|UTF8
modifier|*
modifier|*
name|targetStart
parameter_list|,
name|UTF8
modifier|*
name|targetEnd
parameter_list|,
name|ConversionFlags
name|flags
parameter_list|)
function_decl|;
name|ConversionResult
name|ConvertUTF8toUTF32
parameter_list|(
specifier|const
name|UTF8
modifier|*
modifier|*
name|sourceStart
parameter_list|,
specifier|const
name|UTF8
modifier|*
name|sourceEnd
parameter_list|,
name|UTF32
modifier|*
modifier|*
name|targetStart
parameter_list|,
name|UTF32
modifier|*
name|targetEnd
parameter_list|,
name|ConversionFlags
name|flags
parameter_list|)
function_decl|;
name|ConversionResult
name|ConvertUTF32toUTF8
parameter_list|(
specifier|const
name|UTF32
modifier|*
modifier|*
name|sourceStart
parameter_list|,
specifier|const
name|UTF32
modifier|*
name|sourceEnd
parameter_list|,
name|UTF8
modifier|*
modifier|*
name|targetStart
parameter_list|,
name|UTF8
modifier|*
name|targetEnd
parameter_list|,
name|ConversionFlags
name|flags
parameter_list|)
function_decl|;
name|ConversionResult
name|ConvertUTF16toUTF32
parameter_list|(
specifier|const
name|UTF16
modifier|*
modifier|*
name|sourceStart
parameter_list|,
specifier|const
name|UTF16
modifier|*
name|sourceEnd
parameter_list|,
name|UTF32
modifier|*
modifier|*
name|targetStart
parameter_list|,
name|UTF32
modifier|*
name|targetEnd
parameter_list|,
name|ConversionFlags
name|flags
parameter_list|)
function_decl|;
name|ConversionResult
name|ConvertUTF32toUTF16
parameter_list|(
specifier|const
name|UTF32
modifier|*
modifier|*
name|sourceStart
parameter_list|,
specifier|const
name|UTF32
modifier|*
name|sourceEnd
parameter_list|,
name|UTF16
modifier|*
modifier|*
name|targetStart
parameter_list|,
name|UTF16
modifier|*
name|targetEnd
parameter_list|,
name|ConversionFlags
name|flags
parameter_list|)
function_decl|;
endif|#
directive|endif
name|Boolean
name|isLegalUTF8Sequence
parameter_list|(
specifier|const
name|UTF8
modifier|*
name|source
parameter_list|,
specifier|const
name|UTF8
modifier|*
name|sourceEnd
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

begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment

end_unit

