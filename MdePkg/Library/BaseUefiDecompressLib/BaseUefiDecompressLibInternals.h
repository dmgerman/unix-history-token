begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Internal data structure defintions for Base UEFI Decompress Library.    Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BASE_UEFI_DECOMPRESS_LIB_INTERNALS_H__
end_ifndef

begin_define
define|#
directive|define
name|__BASE_UEFI_DECOMPRESS_LIB_INTERNALS_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Decompression algorithm begins here
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|BITBUFSIZ
value|32
end_define

begin_define
define|#
directive|define
name|MAXMATCH
value|256
end_define

begin_define
define|#
directive|define
name|THRESHOLD
value|3
end_define

begin_define
define|#
directive|define
name|CODE_BIT
value|16
end_define

begin_define
define|#
directive|define
name|BAD_TABLE
value|- 1
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// C: Char&Len Set; P: Position Set; T: exTra Set
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|NC
value|(0xff + MAXMATCH + 2 - THRESHOLD)
end_define

begin_define
define|#
directive|define
name|CBIT
value|9
end_define

begin_define
define|#
directive|define
name|MAXPBIT
value|5
end_define

begin_define
define|#
directive|define
name|TBIT
value|5
end_define

begin_define
define|#
directive|define
name|MAXNP
value|((1U<< MAXPBIT) - 1)
end_define

begin_define
define|#
directive|define
name|NT
value|(CODE_BIT + 3)
end_define

begin_if
if|#
directive|if
name|NT
operator|>
name|MAXNP
end_if

begin_define
define|#
directive|define
name|NPT
value|NT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NPT
value|MAXNP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
modifier|*
name|mSrcBase
decl_stmt|;
comment|// The starting address of compressed data
name|UINT8
modifier|*
name|mDstBase
decl_stmt|;
comment|// The starting address of decompressed data
name|UINT32
name|mOutBuf
decl_stmt|;
name|UINT32
name|mInBuf
decl_stmt|;
name|UINT16
name|mBitCount
decl_stmt|;
name|UINT32
name|mBitBuf
decl_stmt|;
name|UINT32
name|mSubBitBuf
decl_stmt|;
name|UINT16
name|mBlockSize
decl_stmt|;
name|UINT32
name|mCompSize
decl_stmt|;
name|UINT32
name|mOrigSize
decl_stmt|;
name|UINT16
name|mBadTableFlag
decl_stmt|;
name|UINT16
name|mLeft
index|[
literal|2
operator|*
name|NC
operator|-
literal|1
index|]
decl_stmt|;
name|UINT16
name|mRight
index|[
literal|2
operator|*
name|NC
operator|-
literal|1
index|]
decl_stmt|;
name|UINT8
name|mCLen
index|[
name|NC
index|]
decl_stmt|;
name|UINT8
name|mPTLen
index|[
name|NPT
index|]
decl_stmt|;
name|UINT16
name|mCTable
index|[
literal|4096
index|]
decl_stmt|;
name|UINT16
name|mPTTable
index|[
literal|256
index|]
decl_stmt|;
comment|///
comment|/// The length of the field 'Position Set Code Length Array Size' in Block Header.
comment|/// For UEFI 2.0 de/compression algorithm, mPBit = 4.
comment|///
name|UINT8
name|mPBit
decl_stmt|;
block|}
name|SCRATCH_DATA
typedef|;
end_typedef

begin_comment
comment|/**   Read NumOfBit of bits from source into mBitBuf.    Shift mBitBuf NumOfBits left. Read in NumOfBits of bits from source.    @param  Sd        The global scratch data.   @param  NumOfBits The number of bits to shift and read.  **/
end_comment

begin_function_decl
name|VOID
name|FillBuf
parameter_list|(
name|IN
name|SCRATCH_DATA
modifier|*
name|Sd
parameter_list|,
name|IN
name|UINT16
name|NumOfBits
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Get NumOfBits of bits out from mBitBuf.    Get NumOfBits of bits out from mBitBuf. Fill mBitBuf with subsequent   NumOfBits of bits from source. Returns NumOfBits of bits that are   popped out.    @param  Sd        The global scratch data.   @param  NumOfBits The number of bits to pop and read.    @return The bits that are popped out.  **/
end_comment

begin_function_decl
name|UINT32
name|GetBits
parameter_list|(
name|IN
name|SCRATCH_DATA
modifier|*
name|Sd
parameter_list|,
name|IN
name|UINT16
name|NumOfBits
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Creates Huffman Code mapping table according to code length array.    Creates Huffman Code mapping table for Extra Set, Char&Len Set   and Position Set according to code length array.   If TableBits> 16, then ASSERT ().    @param  Sd        The global scratch data.   @param  NumOfChar The number of symbols in the symbol set.   @param  BitLen    Code length array.   @param  TableBits The width of the mapping table.   @param  Table     The table to be created.    @retval  0 OK.   @retval  BAD_TABLE The table is corrupted.  **/
end_comment

begin_function_decl
name|UINT16
name|MakeTable
parameter_list|(
name|IN
name|SCRATCH_DATA
modifier|*
name|Sd
parameter_list|,
name|IN
name|UINT16
name|NumOfChar
parameter_list|,
name|IN
name|UINT8
modifier|*
name|BitLen
parameter_list|,
name|IN
name|UINT16
name|TableBits
parameter_list|,
name|OUT
name|UINT16
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Decodes a position value.    Get a position value according to Position Huffman Table.    @param  Sd The global scratch data.    @return The position value decoded.  **/
end_comment

begin_function_decl
name|UINT32
name|DecodeP
parameter_list|(
name|IN
name|SCRATCH_DATA
modifier|*
name|Sd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads code lengths for the Extra Set or the Position Set.    Read in the Extra Set or Position Set Length Array, then   generate the Huffman code mapping for them.    @param  Sd      The global scratch data.   @param  nn      The number of symbols.   @param  nbit    The number of bits needed to represent nn.   @param  Special The special symbol that needs to be taken care of.    @retval  0 OK.   @retval  BAD_TABLE Table is corrupted.  **/
end_comment

begin_function_decl
name|UINT16
name|ReadPTLen
parameter_list|(
name|IN
name|SCRATCH_DATA
modifier|*
name|Sd
parameter_list|,
name|IN
name|UINT16
name|nn
parameter_list|,
name|IN
name|UINT16
name|nbit
parameter_list|,
name|IN
name|UINT16
name|Special
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Reads code lengths for Char&Len Set.    Read in and decode the Char&Len Set Code Length Array, then   generate the Huffman Code mapping table for the Char&Len Set.    @param  Sd The global scratch data.  **/
end_comment

begin_function_decl
name|VOID
name|ReadCLen
parameter_list|(
name|SCRATCH_DATA
modifier|*
name|Sd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Decode a character/length value.    Read one value from mBitBuf, Get one code from mBitBuf. If it is at block boundary, generates   Huffman code mapping table for Extra Set, Code&Len Set and   Position Set.    @param  Sd The global scratch data.    @return The value decoded.  **/
end_comment

begin_function_decl
name|UINT16
name|DecodeC
parameter_list|(
name|SCRATCH_DATA
modifier|*
name|Sd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Decode the source data and put the resulting data into the destination buffer.    @param  Sd The global scratch data.  **/
end_comment

begin_function_decl
name|VOID
name|Decode
parameter_list|(
name|SCRATCH_DATA
modifier|*
name|Sd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

