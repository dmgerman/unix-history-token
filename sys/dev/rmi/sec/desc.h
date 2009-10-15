begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2009 RMI Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of RMI Corporation, nor the names of its contributors,  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * RMI_BSD */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DESC_H_
end_ifndef

begin_define
define|#
directive|define
name|_DESC_H_
end_define

begin_define
define|#
directive|define
name|ONE_BIT
value|0x0000000000000001ULL
end_define

begin_define
define|#
directive|define
name|TWO_BITS
value|0x0000000000000003ULL
end_define

begin_define
define|#
directive|define
name|THREE_BITS
value|0x0000000000000007ULL
end_define

begin_define
define|#
directive|define
name|FOUR_BITS
value|0x000000000000000fULL
end_define

begin_define
define|#
directive|define
name|FIVE_BITS
value|0x000000000000001fULL
end_define

begin_define
define|#
directive|define
name|SIX_BITS
value|0x000000000000003fULL
end_define

begin_define
define|#
directive|define
name|SEVEN_BITS
value|0x000000000000007fULL
end_define

begin_define
define|#
directive|define
name|EIGHT_BITS
value|0x00000000000000ffULL
end_define

begin_define
define|#
directive|define
name|NINE_BITS
value|0x00000000000001ffULL
end_define

begin_define
define|#
directive|define
name|ELEVEN_BITS
value|0x00000000000007ffULL
end_define

begin_define
define|#
directive|define
name|TWELVE_BITS
value|0x0000000000000fffULL
end_define

begin_define
define|#
directive|define
name|FOURTEEN_BITS
value|0x0000000000003fffULL
end_define

begin_define
define|#
directive|define
name|TWENTYFOUR_BITS
value|0x0000000000ffffffULL
end_define

begin_define
define|#
directive|define
name|THIRTY_TWO_BITS
value|0x00000000ffffffffULL
end_define

begin_define
define|#
directive|define
name|THIRTY_FIVE_BITS
value|0x00000007ffffffffULL
end_define

begin_define
define|#
directive|define
name|FOURTY_BITS
value|0x000000ffffffffffULL
end_define

begin_define
define|#
directive|define
name|MSG_IN_CTL_LEN_BASE
value|40
end_define

begin_define
define|#
directive|define
name|MSG_IN_CTL_ADDR_BASE
value|0
end_define

begin_define
define|#
directive|define
name|GET_FIELD
parameter_list|(
name|word
parameter_list|,
name|field
parameter_list|)
define|\
value|((word)& (field ## _MASK))>> (field ## _LSB)
end_define

begin_define
define|#
directive|define
name|FIELD_VALUE
parameter_list|(
name|field
parameter_list|,
name|value
parameter_list|)
value|(((value)& (field ## _BITS))<< (field ## _LSB))
end_define

begin_comment
comment|/*  * NOTE: this macro expects 'word' to be uninitialized (i.e. zeroed)  */
end_comment

begin_define
define|#
directive|define
name|SET_FIELD
parameter_list|(
name|word
parameter_list|,
name|field
parameter_list|,
name|value
parameter_list|)
define|\
value|{ (word) |=  (((value)& (field ## _BITS))<< (field ## _LSB)); }
end_define

begin_comment
comment|/*  * This macro clears 'word', then sets the value  */
end_comment

begin_define
define|#
directive|define
name|CLEAR_SET_FIELD
parameter_list|(
name|word
parameter_list|,
name|field
parameter_list|,
name|value
parameter_list|)
define|\
value|{ (word)&= ~((field ## _BITS)<< (field ## _LSB)); \    (word) |=  (((value)& (field ## _BITS))<< (field ## _LSB)); }
end_define

begin_comment
comment|/*  * NOTE: May be used to build value specific mask   *        (e.g.  GEN_MASK(CTL_DSC_CPHR_3DES,CTL_DSC_CPHR_LSB)  */
end_comment

begin_define
define|#
directive|define
name|GEN_MASK
parameter_list|(
name|bits
parameter_list|,
name|lsb
parameter_list|)
value|((bits)<< (lsb))
end_define

begin_comment
comment|/*  * Security block data and control exchange  *  * A 2-word message ring descriptor is used to pass a pointer to the control descriptor data structure  * and a pointer to the packet descriptor data structure:  *  *  63  61 60                 54      53      52    49 48            45 44    40  *  39                                                     5 4                 0  *  ---------------------------------------------------------------------------------------------------------------------------------------------------------  * | Ctrl | Resp Dest Id Entry0 | IF_L2ALLOC | UNUSED | Control Length | UNUSED  * | 35 MSB of address of control descriptor data structure | Software Scratch0  * |  *  ---------------------------------------------------------------------------------------------------------------------------------------------------------  *    3              7                1          4             4           5  *    35                                       5  *  *  63  61 60    54     53          52             51        50    46      45       44    40 39                                                    5 4      0  *  ---------------------------------------------------------------------------------------------------------------------------------------------------------  * | Ctrl | UNUSED | WRB_COH | WRB_L2ALLOC | DF_PTR_L2ALLOC | UNUSED | Data Length | UNUSED | 35 MSB of address of packet descriptor data structure | UNUSED |  *  ---------------------------------------------------------------------------------------------------------------------------------------------------------  *    3       7         1          1               1            5           1          5                                35                              5  *  * Addresses assumed to be cache-line aligned, i.e., Address[4:0] ignored (using 5'h00 instead)  *  * Control length is the number of control cachelines to be read so user needs  * to round up  * the control length to closest integer multiple of 32 bytes. Note that at  * present (08/12/04)  * the longest (sensical) ctrl structure is<= 416 bytes, i.e., 13 cachelines.  *  * The packet descriptor data structure size is fixed at 1 cacheline (32 bytes).  * This effectively makes "Data Length" a Load/NoLoad bit. NoLoad causes an abort.  *  *  * Upon completion of operation, the security block returns a 2-word free descriptor  * in the following format:  *  *  63  61 60            54 53   52 51       49   48   47               40 39                                                  0  *  ----------------------------------------------------------------------------------------------------------------------------  * | Ctrl | Destination Id | 2'b00 | Desc Ctrl | 1'b0 | Instruction Error |    Address of control descriptor data structure     |  *  ----------------------------------------------------------------------------------------------------------------------------  * | Ctrl | Destination Id | 2'b00 | Desc Ctrl | 1'b0 |     Data Error    |    Address of packet descriptor data structure      |  *  ----------------------------------------------------------------------------------------------------------------------------  *  * The Instruction and Data Error codes are enumerated in the   * ControlDescriptor and PacketDescriptor sections below  *  */
end_comment

begin_comment
comment|/*  * Operating assumptions  * =====================  *  *   *	        -> For all IpSec ops, I assume that all the IP/IPSec/TCP headers  *		   and the data are present at the specified source addresses.  *		   I also assume that all necessary header data already exists  *		   at the destination. Additionally, in AH I assume that all  *		   mutable fields (IP.{TOS, Flags, Offset, TTL, Header_Checksum})   *		   and the AH.Authentication_Data have been zeroed by the client.  *  *  *		-> In principle, the HW can calculate TCP checksums on both  *		   incoming and outgoing data; however, since the TCP header  *		   contains the TCP checksum of the plain payload and the header  *		   is encrypted, two passes would be necessary to do checksum + encryption  *                 for outgoing messages;  *		   therefore the checksum engine will likely only be used during decryption  *                 (incoming).  *  *  *		-> For all operations involving TCP checksum, I assume the client has filled  *		   the TCP checksum field with the appropriate value:  *  *			    - 0 for generation phase  *			    - actual value for verification phase (expecting 0 result)  *  *  *		-> For ESP tunnel, the original IP header exists between the end of the  *		   ESP header and the beginning of the TCP header; it is assumed that the  *		   maximum length of this header is 16 k(32bit)words (used in CkSum_Offset).  *  *  *		-> The authentication data is merely written to the destination address;  *		   the client is left with the task of comparing to the data in packet  *		   in decrypt.  *  *              -> PacketDescriptor_t.dstLLWMask relevant to AES CTR mode only but it will  *                 affect all AES-related operations. It will not affect DES/3DES/bypass ops.  *                 The mask is applied to data as it emerges from the AES engine for the sole  *                 purpose of providing the authenticator and cksum engines with correct data.  *                 CAVEAT: the HW does not mask the incoming data. It is the user's responsibility  *                 to set to 0 the corresponding data in memory. If the surplus data is not masked  *                 in memory, cksum/auth results will be incorrect if those engines receive data  *                 straight from memory (i.e., not from cipher, as it happens while decoding)  */
end_comment

begin_comment
comment|/*  * Fragmentation and offset related notes  * ======================================  *  *  *      A) Rebuilding packets from fragments on dword boundaries. The discussion  *         below is exemplified by tests memcpy_all_off_frags and memcpy_same_off_frags  *   *	        1) The Offset before data/iv on first fragment is ALWAYS written back  *                 Non-zero dst dword or global offsets may cause more data to be   *                 written than the user-specified length.  *  *  *                 Example:  *                 --------  *  *                 Below is a source (first fragment) packet (@ ADD0 cache-aligned address).  *                 Assume we just copy it and relevant data starts on  *                 dword 3 so Cipher_Offset = IV_Offset = 3 (dwords).  *                 D0X denotes relevant data and G denotes dont care data.  *                 Offset data is also copied so Packet_Legth = 9 (dwords) * 8 = 72 (bytes)  *                 Segment_src_address = ADD0  *  *                 If we want to, e.g., copy so that the relevant (i.e., D0X) data  *                 starts at (cache-aligned address) ADD1, we need to specify  *                 Dst_dword_offset = 1 so D00 is moved from dword position 3 to 0 on next cache-line  *                 Cipher_dst_address = ADD1 - 0x20 so D00 is written to ADD1  *  *                 Note that the security engine always writes full cachelines  *                 therefore, data written to dword0 0 of ADD1 (denoted w/ ?) is what the sec pipe  *                 write back buffer contained from previous op.  *  *  *                      SOURCE:                                                 DESTINATION:  *                      -------                                                 ------------  *  *                      Segment_src_address = ADD0                              Cipher_dst_address = ADD1 - 0x20  *                      Packet_Legth        = 72                                Dst_dword_offset   = 1  *                      Cipher_Offset       = 3  *                      IV_Offset           = 3  *                      Use_IV              = ANY  *                        *  *  *                         3     2     1     0                                  3     2     1     0  *                       -----------------------                              -----------------------  *                      | D00 | G   | G   | G   |<- ADD0                    | G   | G   | G   | ?   |<- ADD1 - 0x20  *                       -----------------------                              -----------------------  *                      | D04 | D03 | D02 | D01 |                            | D03 | D02 | D01 | D00 |<- ADD1  *                       -----------------------                              -----------------------  *                      |     |     |     | D05 |                            |     |     | D05 | D04 |  *                       -----------------------                              -----------------------  *   *	        2) On fragments following the first, IV_Offset is overloaded to mean data offset  *                 (number of dwords to skip from beginning of cacheline before starting processing)  *                 and Use_IV is overloaded to mean do writeback the offset (in the clear).  *                 These fields in combination with Dst_dword_offset allow packet fragments with  *                 arbitrary boundaries/lengthd to be reasembled.  *  *  *                 Example:  *                 --------  *  *                 Assume data above was first fragment of a packet we'd like to merge to  *                 (second) fragment below located at ADD2. The written data should follow  *                 the previous data without gaps or overwrites. To achieve this, one should  *                 assert the "Next" field on the previous fragment and use self-explanatory  *                 set of parameters below  *  *  *                      SOURCE:                                                 DESTINATION:  *                      -------                                                 ------------  *  *                      Segment_src_address = ADD2                              Cipher_dst_address = ADD1 + 0x20  *                      Packet_Legth        = 104                               Dst_dword_offset   = 1  *                      IV_Offset           = 1  *                      Use_IV              = 0  *                        *  *  *                         3     2     1     0                                  3     2     1     0  *                       -----------------------                              -----------------------  *                      | D12 | D11 | D10 | G   |<- ADD2                    | G   | G   | G   | ?   |<- ADD1 - 0x20  *                       -----------------------                              -----------------------  *                      | D16 | D15 | D14 | D13 |                            | D03 | D02 | D01 | D00 |<- ADD1  *                       -----------------------                              -----------------------  *                      | D1a | D19 | D18 | D17 |                            | D11 | D10 | D05 | D04 |<- ADD1 + 0x20  *                       -----------------------                              -----------------------  *                      |     |     |     | D1b |                            | D15 | D14 | D13 | D12 |  *                       -----------------------                              -----------------------  *                                                                           | D19 | D18 | D17 | D16 |  *                                                                            -----------------------  *                                                                           |     |     | D1b | D1a |  *                                                                            -----------------------  *  *                 It is note-worthy that the merging can only be achieved if Use_IV is 0. Indeed, the security  *                 engine always writes full lines, therefore ADD1 + 0x20 will be re-written. Setting Use_IV to 0  *                 will allow the sec pipe write back buffer to preserve D04, D05 from previous frag and only  *                 receive D10, D11 thereby preserving the integrity of the previous data.  *   *	        3) On fragments following the first, !UseIV in combination w/ Dst_dword_offset>= (4 - IV_Offset)  *                 will cause a wraparound of the write thus achieving all 16 possible (Initial_Location, Final_Location)  *                 combinations for the data.  *  *  *                 Example:  *                 --------  *  *                 Contiguously merging 2 data sets above with a third located at ADD3. If this is the last fragment,   *                 reset its Next bit.  *  *  *                      SOURCE:                                                 DESTINATION:  *                      -------                                                 ------------  *  *                      Segment_src_address = ADD3                              Cipher_dst_address = ADD1 + 0x80  *                      Packet_Legth        = 152                               Dst_dword_offset   = 3  *                      IV_Offset           = 3  *                      Use_IV              = 0  *                        *  *  *                         3     2     1     0                                  3     2     1     0  *                       -----------------------                              -----------------------  *                      | D20 | G   | G   | G   |<- ADD2                    | G   | G   | G   | ?   |<- ADD1 - 0x20  *                       -----------------------                              -----------------------  *                      | D24 | D23 | D22 | D21 |                            | D03 | D02 | D01 | D00 |<- ADD1  *                       -----------------------                              -----------------------  *                      | D28 | D27 | D26 | D25 |                            | D11 | D10 | D05 | D04 |<- ADD1 + 0x20  *                       -----------------------                              -----------------------  *                      | D2c | D2b | D2a | D29 |                            | D15 | D14 | D13 | D12 |  *                       -----------------------                              -----------------------  *                      |     | D2f | D2e | D2d |                            | D19 | D18 | D17 | D16 |  *                       -----------------------                              -----------------------  *                                                                           | D21 | D20 | D1b | D1a |<- ADD1 + 0x80  *                                                                            -----------------------  *                                                                           | D25 | D24 | D23 | D22 |   *                                                                            -----------------------  *                                                                           | D29 | D28 | D27 | D26 |   *                                                                            -----------------------  *                                                                           | D2d | D2c | D2b | D2a |   *                                                                            -----------------------  *                                                                           |(D2d)|(D2c)| D2f | D2e |   *                                                                            -----------------------  *  *                 It is worth noticing that always writing full-lines causes the last 2 dwords in the reconstituted  *                 packet to be unnecessarily written: (D2d) and (D2c)  *  *  *  *      B) Implications of fragmentation on AES  *   *	        1) AES is a 128 bit block cipher; therefore it requires an even dword total data length  *                 Data fragments (provided there are more than 1) are allowed to have odd dword  *                 data lengths provided the total length (cumulated over fragments) is an even dword  *                 count; an error will be generated otherwise, upon receiving the last fragment descriptor  *                 (see error conditions below).  *  *              2) While using fragments with AES, a fragment (other than first) starting with a != 0 (IV) offset  *                 while the subsequent total dword count given to AES is odd may not be required to write  *                 its offset (UseIV). Doing so will cause an error (see error conditions below).  *  *  *                 Example:  *                 --------  *  *                 Suppose the first fragment has an odd DATA dword count and USES AES (as seen below)  *  *                      SOURCE:                                                 DESTINATION:  *                      -------                                                 ------------  *  *                      Segment_src_address = ADD0                              Cipher_dst_address = ADD1  *                      Packet_Legth        = 64                                Dst_dword_offset   = 1  *                      Cipher_Offset       = 3  *                      IV_Offset           = 1  *                      Use_IV              = 1  *                      Cipher              = Any AES  *                      Next                = 1  *                        *  *   *  *                         3     2     1     0                                  3     2     1     0  *                       -----------------------                              -----------------------  *                      | D00 | IV1 | IV0 | G   |<- ADD0                    | E00 | IV1 | IV0 | G   |<- ADD1  *                       -----------------------                              -----------------------  *                      | D04 | D03 | D02 | D01 |                            | X   | E03 | E02 | E01 |  *                       -----------------------                              -----------------------  *  *                 At the end of processing of the previous fragment, the AES engine input buffer has D04  *                 and waits for next dword, therefore the writeback buffer cannot finish writing the fragment  *                 to destination (X instead of E04).  *  *                 If a second fragment now arrives with a non-0 offset and requires the offset data to be  *                 written to destination, the previous write (still needing the arrival of the last dword  *                 required by the AES to complete the previous operation) cannot complete before the present  *                 should start causing a deadlock.  */
end_comment

begin_comment
comment|/*  *  Command Control Word for Message Ring Descriptor  */
end_comment

begin_comment
comment|/* #define MSG_CMD_CTL_CTL       */
end_comment

begin_define
define|#
directive|define
name|MSG_CMD_CTL_CTL_LSB
value|61
end_define

begin_define
define|#
directive|define
name|MSG_CMD_CTL_CTL_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|MSG_CMD_CTL_CTL_MASK
value|(MSG_CMD_CTL_CTL_BITS<< MSG_CMD_CTL_CTL_LSB)
end_define

begin_comment
comment|/* #define MSG_CMD_CTL_ID */
end_comment

begin_define
define|#
directive|define
name|MSG_CMD_CTL_ID_LSB
value|54
end_define

begin_define
define|#
directive|define
name|MSG_CMD_CTL_ID_BITS
value|SEVEN_BITS
end_define

begin_define
define|#
directive|define
name|MSG_CMD_CTL_ID_MASK
value|(MSG_CMD_CTL_ID_BITS<< MSG_CMD_CTL_ID_LSB)
end_define

begin_comment
comment|/* #define MSG_CMD_CTL_LEN */
end_comment

begin_define
define|#
directive|define
name|MSG_CMD_CTL_LEN_LSB
value|45
end_define

begin_define
define|#
directive|define
name|MSG_CMD_CTL_LEN_BITS
value|FOUR_BITS
end_define

begin_define
define|#
directive|define
name|MSG_CMD_CTL_LEN_MASK
value|(MSG_CMD_CTL_LEN_BITS<< MSG_CMD_CTL_LEN_LSB)
end_define

begin_comment
comment|/* #define MSG_CMD_CTL_ADDR */
end_comment

begin_define
define|#
directive|define
name|MSG_CMD_CTL_ADDR_LSB
value|0
end_define

begin_define
define|#
directive|define
name|MSG_CMD_CTL_ADDR_BITS
value|FOURTY_BITS
end_define

begin_define
define|#
directive|define
name|MSG_CMD_CTL_ADDR_MASK
value|(MSG_CMD_CTL_ADDR_BITS<< MSG_CMD_CTL_ADDR_LSB)
end_define

begin_define
define|#
directive|define
name|MSG_CMD_CTL_MASK
value|(MSG_CMD_CTL_CTL_MASK | \                                MSG_CMD_CTL_LEN_MASK | MSG_CMD_CTL_ADDR_MASK)
end_define

begin_comment
comment|/*  *  Command Data Word for Message Ring Descriptor  */
end_comment

begin_comment
comment|/* #define MSG_IN_DATA_CTL */
end_comment

begin_define
define|#
directive|define
name|MSG_CMD_DATA_CTL_LSB
value|61
end_define

begin_define
define|#
directive|define
name|MSG_CMD_DATA_CTL_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|MSG_CMD_DATA_CTL_MASK
value|(MSG_CMD_DATA_CTL_BITS<< MSG_CMD_DATA_CTL_LSB)
end_define

begin_comment
comment|/* #define MSG_CMD_DATA_LEN */
end_comment

begin_define
define|#
directive|define
name|MSG_CMD_DATA_LEN_LOAD
value|1
end_define

begin_define
define|#
directive|define
name|MSG_CMD_DATA_LEN_LSB
value|45
end_define

begin_define
define|#
directive|define
name|MSG_CMD_DATA_LEN_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|MSG_CMD_DATA_LEN_MASK
value|(MSG_CMD_DATA_LEN_BITS<< MSG_CMD_DATA_LEN_LSB)
end_define

begin_comment
comment|/* #define MSG_CMD_DATA_ADDR */
end_comment

begin_define
define|#
directive|define
name|MSG_CMD_DATA_ADDR_LSB
value|0
end_define

begin_define
define|#
directive|define
name|MSG_CMD_DATA_ADDR_BITS
value|FOURTY_BITS
end_define

begin_define
define|#
directive|define
name|MSG_CMD_DATA_ADDR_MASK
value|(MSG_CMD_DATA_ADDR_BITS<< MSG_CMD_DATA_ADDR_LSB)
end_define

begin_define
define|#
directive|define
name|MSG_CMD_DATA_MASK
value|(MSG_CMD_DATA_CTL_MASK | \                                MSG_CMD_DATA_LEN_MASK | MSG_CMD_DATA_ADDR_MASK)
end_define

begin_comment
comment|/*  * Upon completion of operation, the Sec block returns a 2-word free descriptor  * in the following format:  *  *  63  61 60            54 53   52 51       49  48          40 39             0  *  ----------------------------------------------------------------------------  * | Ctrl | Destination Id | 2'b00 | Desc Ctrl | Control Error | Source Address |  *  ----------------------------------------------------------------------------  * | Ctrl | Destination Id | 2'b00 | Desc Ctrl |   Data Error  | Dest Address   |  *  ----------------------------------------------------------------------------  *  * The Control and Data Error codes are enumerated below  *  *                                Error conditions  *                                ================  *  *             Control Error Code                  Control Error Condition  *             ------------------                  ---------------------------  *             9'h000                              No Error  *             9'h001                              Unknown Cipher Op                      ( Cipher == 3'h{6,7})  *             9'h002                              Unknown or Illegal Mode                ((Mode   == 3'h{2,3,4}& !AES) | (Mode   == 3'h{5,6,7}))  *             9'h004                              Unsupported CkSum Src                  (CkSum_Src   == 2'h{2,3}& CKSUM)  *             9'h008                              Forbidden CFB Mask                     (AES& CFBMode& UseNewKeysCFBMask& CFBMask[7]& (| CFBMask[6:0]))  *             9'h010                              Unknown Ctrl Op                        ((| Ctrl[63:37]) | (| Ctrl[15:14]))  *             9'h020                              UNUSED  *             9'h040                              UNUSED  *             9'h080                              Data Read Error  *             9'h100                              Descriptor Ctrl Field Error            (D0.Ctrl != SOP || D1.Ctrl != EOP)  *  *             Data Error Code                     Data Error Condition  *             ---------------                     --------------------  *             9'h000                              No Error  *             9'h001                              Insufficient Data To Cipher            (Packet_Length<= (Cipher_Offset or IV_Offset))  *             9'h002                              Illegal IV Location                    ((Cipher_Offset<  IV_Offset) | (Cipher_Offset<= IV_Offset& AES& ~CTR))  *             9'h004                              Illegal Wordcount To AES               (Packet_Length[3] != Cipher_Offset[0]& AES)  *             9'h008                              Illegal Pad And ByteCount Spec         (Hash_Byte_Count != 0& !Pad_Hash)  *             9'h010                              Insufficient Data To CkSum             ({Packet_Length, 1'b0}<= CkSum_Offset)  *             9'h020                              Unknown Data Op                        ((| dstLLWMask[63:60]) | (| dstLLWMask[57:40]) | (| authDst[63:40]) | (| ckSumDst[63:40]))  *             9'h040                              Insufficient Data To Auth              ({Packet_Length}<= Auth_Offset)  *             9'h080                              Data Read Error  *             9'h100                              UNUSED  */
end_comment

begin_comment
comment|/*  * Result Control Word for Message Ring Descriptor  */
end_comment

begin_comment
comment|/* #define MSG_RSLT_CTL_CTL */
end_comment

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_CTL_LSB
value|61
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_CTL_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_CTL_MASK
define|\
value|(MSG_RSLT_CTL_CTL_BITS<< MSG_RSLT_CTL_CTL_LSB)
end_define

begin_comment
comment|/* #define MSG_RSLT_CTL_DST_ID */
end_comment

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_DST_ID_LSB
value|54
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_DST_ID_BITS
value|SEVEN_BITS
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_DST_ID_MASK
define|\
value|(MSG_RSLT_CTL_DST_ID_BITS<< MSG_RSLT_CTL_DST_ID_LSB)
end_define

begin_comment
comment|/* #define MSG_RSLT_CTL_DSC_CTL */
end_comment

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_DSC_CTL_LSB
value|49
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_DSC_CTL_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_DSC_CTL_MASK
define|\
value|(MSG_RSLT_CTL_DSC_CTL_BITS<< MSG_RSLT_CTL_DSC_CTL_LSB)
end_define

begin_comment
comment|/* #define MSG_RSLT_CTL_INST_ERR */
end_comment

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_INST_ERR_LSB
value|40
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_INST_ERR_BITS
value|NINE_BITS
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_INST_ERR_MASK
define|\
value|(MSG_RSLT_CTL_INST_ERR_BITS<< MSG_RSLT_CTL_INST_ERR_LSB)
end_define

begin_comment
comment|/* #define MSG_RSLT_CTL_DSC_ADDR */
end_comment

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_DSC_ADDR_LSB
value|0
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_DSC_ADDR_BITS
value|FOURTY_BITS
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_DSC_ADDR_MASK
define|\
value|(MSG_RSLT_CTL_DSC_ADDR_BITS<< MSG_RSLT_CTL_DSC_ADDR_LSB)
end_define

begin_comment
comment|/* #define MSG_RSLT_CTL_MASK */
end_comment

begin_define
define|#
directive|define
name|MSG_RSLT_CTL_MASK
define|\
value|(MSG_RSLT_CTL_CTRL_MASK | MSG_RSLT_CTL_DST_ID_MASK | \   MSG_RSLT_CTL_DSC_CTL_MASK | MSG_RSLT_CTL_INST_ERR_MASK | \   MSG_RSLT_CTL_DSC_ADDR_MASK)
end_define

begin_comment
comment|/*  * Result Data Word for Message Ring Descriptor  */
end_comment

begin_comment
comment|/* #define MSG_RSLT_DATA_CTL */
end_comment

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_CTL_LSB
value|61
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_CTL_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_CTL_MASK
define|\
value|(MSG_RSLT_DATA_CTL_BITS<< MSG_RSLT_DATA_CTL_LSB)
end_define

begin_comment
comment|/* #define MSG_RSLT_DATA_DST_ID */
end_comment

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_DST_ID_LSB
value|54
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_DST_ID_BITS
value|SEVEN_BITS
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_DST_ID_MASK
define|\
value|(MSG_RSLT_DATA_DST_ID_BITS<< MSG_RSLT_DATA_DST_ID_LSB)
end_define

begin_comment
comment|/* #define MSG_RSLT_DATA_DSC_CTL */
end_comment

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_DSC_CTL_LSB
value|49
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_DSC_CTL_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_DSC_CTL_MASK
define|\
value|(MSG_RSLT_DATA_DSC_CTL_BITS<< MSG_RSLT_DATA_DSC_CTL_LSB)
end_define

begin_comment
comment|/* #define MSG_RSLT_DATA_INST_ERR */
end_comment

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_INST_ERR_LSB
value|40
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_INST_ERR_BITS
value|NINE_BITS
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_INST_ERR_MASK
define|\
value|(MSG_RSLT_DATA_INST_ERR_BITS<< MSG_RSLT_DATA_INST_ERR_LSB)
end_define

begin_comment
comment|/* #define MSG_RSLT_DATA_DSC_ADDR */
end_comment

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_DSC_ADDR_LSB
value|0
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_DSC_ADDR_BITS
value|FOURTY_BITS
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_DSC_ADDR_MASK
define|\
value|(MSG_RSLT_DATA_DSC_ADDR_BITS<< MSG_RSLT_DATA_DSC_ADDR_LSB)
end_define

begin_define
define|#
directive|define
name|MSG_RSLT_DATA_MASK
define|\
value|(MSG_RSLT_DATA_CTRL_MASK | MSG_RSLT_DATA_DST_ID_MASK | \   MSG_RSLT_DATA_DSC_CTL_MASK | MSG_RSLT_DATA_INST_ERR_MASK | \   MSG_RSLT_DATA_DSC_ADDR_MASK)
end_define

begin_comment
comment|/*  * Common Message Definitions  *  */
end_comment

begin_comment
comment|/* #define MSG_CTL_OP_ADDR */
end_comment

begin_define
define|#
directive|define
name|MSG_CTL_OP_ADDR_LSB
value|0
end_define

begin_define
define|#
directive|define
name|MSG_CTL_OP_ADDR_BITS
value|FOURTY_BITS
end_define

begin_define
define|#
directive|define
name|MSG_CTL_OP_ADDR_MASK
value|(MSG_CTL_OP_ADDR_BITS<< MSG_CTL_OP_ADDR_LSB)
end_define

begin_define
define|#
directive|define
name|MSG_CTL_OP_TYPE
end_define

begin_define
define|#
directive|define
name|MSG_CTL_OP_TYPE_LSB
value|3
end_define

begin_define
define|#
directive|define
name|MSG_CTL_OP_TYPE_BITS
value|TWO_BITS
end_define

begin_define
define|#
directive|define
name|MSG_CTL_OP_TYPE_MASK
define|\
value|(MSG_CTL_OP_TYPE_BITS<< MSG_CTL_OP_TYPE_LSB)
end_define

begin_define
define|#
directive|define
name|MSG0_CTL_OP_ENGINE_SYMKEY
value|0x01
end_define

begin_define
define|#
directive|define
name|MSG0_CTL_OP_ENGINE_PUBKEY
value|0x02
end_define

begin_define
define|#
directive|define
name|MSG1_CTL_OP_SYMKEY_PIPE0
value|0x00
end_define

begin_define
define|#
directive|define
name|MSG1_CTL_OP_SYMKEY_PIPE1
value|0x01
end_define

begin_define
define|#
directive|define
name|MSG1_CTL_OP_SYMKEY_PIPE2
value|0x02
end_define

begin_define
define|#
directive|define
name|MSG1_CTL_OP_SYMKEY_PIPE3
value|0x03
end_define

begin_define
define|#
directive|define
name|MSG1_CTL_OP_PUBKEY_PIPE0
value|0x00
end_define

begin_define
define|#
directive|define
name|MSG1_CTL_OP_PUBKEY_PIPE1
value|0x01
end_define

begin_define
define|#
directive|define
name|MSG1_CTL_OP_PUBKEY_PIPE2
value|0x02
end_define

begin_define
define|#
directive|define
name|MSG1_CTL_OP_PUBKEY_PIPE3
value|0x03
end_define

begin_comment
comment|/*       /----------------------------------------\  *       |                                        |  *       |   ControlDescriptor_s datastructure    |  *       |                                        |  *       \----------------------------------------/  *  *  *       ControlDescriptor_t.Instruction  *       -------------------------------  *  *   63    44         43               42            41              40           39        35 34    32 31  29     28  *  --------------------------------------------------------------------------------------------------------------------  * || UNUSED || OverrideCipher | Arc4Wait4Save | SaveArc4State | LoadArc4State | Arc4KeyLen | Cipher | Mode | InCp_Key || ... CONT ...  *  --------------------------------------------------------------------------------------------------------------------  *      20            1                1              1               1               5          3       3        1  *<-----------------------------------------------CIPHER--------------------------------------------------->  *  *   27    25     24      23   22     21     20      19    17    16     15     0  *  -----------------------------------------------------------------------------  * || UNUSED | Hash_Hi | HMAC | Hash_Lo | InHs_Key || UNUSED || CkSum || UNUSED ||  *  -----------------------------------------------------------------------------  *      3         1       1        2         1          3        1        16  *<---------------------HASH---------------------><-----------CKSUM----------->  *  *  X0  CIPHER.Arc4Wait4Save   =                   If op is Arc4 and it requires state saving, then  *                                                 setting this bit will cause the current op to  *                                                 delay subsequent op loading until saved state data  *                                                 becomes visible.  *      CIPHER.OverrideCipher  =                   Override encryption if PacketDescriptor_t.dstDataSettings.CipherPrefix  *                                                 is set; data will be copied out (and optionally auth/cksum)  *                                                 in the clear. This is used in GCM mode if auth only as we  *                                                 still need E(K, 0) calculated by cipher. Engine behavior is  *                                                 undefined if this bit is set and CipherPrefix is not.  *  X0         SaveArc4State   =                   Save Arc4 state at the end of Arc4 operation  *  X0         LoadArc4State   =                   Load Arc4 state at the beginning of an Arc4 operation  *                                                 This overriden by the InCp_Key setting for Arc4  *             Arc4KeyLen      =                   Length in bytes of Arc4 key (0 is interpreted as 32)  *                                                 Ignored for other ciphers  *                                                 For ARC4, IFetch/IDecode will always read exactly 4  *                                                 consecutive dwords into its CipherKey{0,3} regardless  *                                                 of this quantity; it will however only use the specified  *                                                 number of bytes.          *             Cipher          =        3'b000     Bypass  *                                      3'b001     DES  *                                      3'b010     3DES  *                                      3'b011     AES 128-bit key  *                                      3'b100     AES 192-bit key  *                                      3'b101     AES 256-bit key  *                                      3'b110     ARC4  *                                      3'b111     Kasumi f8  *                                      Remainder  UNDEFINED  *             Mode            =        3'b000     ECB  *                                      3'b001     CBC  *                                      3'b010     CFB (AES only, otherwise undefined)  *                                      3'b011     OFB (AES only, otherwise undefined)  *                                      3'b100     CTR (AES only, otherwise undefined)  *                                      3'b101     F8  (AES only, otherwise undefined)  *                                      Remainder  UNDEFINED  *             InCp_Key        =        1'b0       Preserve old Cipher Keys  *                                      1'b1       Load new Cipher Keys from memory to local registers  *                                                 and recalculate the Arc4 Sbox if Arc4 Cipher chosen;  *                                                 This overrides LoadArc4State setting.  *        HASH.HMAC            =        1'b0       Hash without HMAC  *                                      1'b1       Hash with HMAC   *                                                 Needs to be set to 0 for GCM and Kasumi F9 authenticators  *                                                 otherwise unpredictable results will be generated  *             Hash            =        2'b00      Hash NOP  *                                      2'b01      MD5  *                                      2'b10      SHA-1  *                                      2'b11      SHA-256  *                                      3'b100     SHA-384  *                                      3'b101     SHA-512  *                                      3'b110     GCM  *                                      3'b111     Kasumi f9  *             InHs_Key        =        1'b0       Preserve old HMAC Keys  *                                                 If GCM is selected as authenticator, leaving this bit  *                                                 at 0 will cause the engine to use the old H value.  *                                                 It will use the old SCI inside the decoder if  *                                                 CFBMask[1:0] == 2'b11.  *                                                 If Kasumi F9 authenticator, using 0 preserves  *                                                 old keys (IK) in decoder.  *                                      1'b1       Load new HMAC Keys from memory to local registers  *                                                 Setting this bit while Cipher=Arc4 and LoadArc4State=1  *                                                 causes the decoder to load the Arc4 state from the  *                                                 cacheline following the HMAC keys (Whether HASH.HMAC  *                                                 is set or not).  *                                                 If GCM is selected as authenticator, setting this bit  *                                                 causes both H (16 bytes) and SCI (8 bytes) to be loaded  *                                                 from memory to the decoder. H will be loaded to the engine  *                                                 but SCI is only loaded to the engine if CFBMask[1:0] == 2'b11.  *                                                 If Kasumi F9 authenticator, using 1 loads new keys (IK)  *                                                 from memory to decoder.  *    CHECKSUM.CkSum           =        1'b0       CkSum NOP  *                                      1'b1       INTERNET_CHECKSUM  *  *  *  */
end_comment

begin_comment
comment|/* #define CTRL_DSC_OVERRIDECIPHER */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_OVERRIDECIPHER_OFF
value|0
end_define

begin_define
define|#
directive|define
name|CTL_DSC_OVERRIDECIPHER_ON
value|1
end_define

begin_define
define|#
directive|define
name|CTL_DSC_OVERRIDECIPHER_LSB
value|43
end_define

begin_define
define|#
directive|define
name|CTL_DSC_OVERRIDECIPHER_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|CTL_DSC_OVERRIDECIPHER_MASK
value|(CTL_DSC_OVERRIDECIPHER_BITS<< CTL_DSC_OVERRIDECIPHER_LSB)
end_define

begin_comment
comment|/* #define CTRL_DSC_ARC4_WAIT4SAVE */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_WAIT4SAVE_OFF
value|0
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_WAIT4SAVE_ON
value|1
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_WAIT4SAVE_LSB
value|42
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_WAIT4SAVE_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_WAIT4SAVE_MASK
value|(CTL_DSC_ARC4_WAIT4SAVE_BITS<< CTL_DSC_ARC4_WAIT4SAVE_LSB)
end_define

begin_comment
comment|/* #define CTRL_DSC_ARC4_SAVESTATE */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_SAVESTATE_OFF
value|0
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_SAVESTATE_ON
value|1
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_SAVESTATE_LSB
value|41
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_SAVESTATE_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_SAVESTATE_MASK
value|(CTL_DSC_ARC4_SAVESTATE_BITS<< CTL_DSC_ARC4_SAVESTATE_LSB)
end_define

begin_comment
comment|/* #define CTRL_DSC_ARC4_LOADSTATE */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_LOADSTATE_OFF
value|0
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_LOADSTATE_ON
value|1
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_LOADSTATE_LSB
value|40
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_LOADSTATE_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_LOADSTATE_MASK
value|(CTL_DSC_ARC4_LOADSTATE_BITS<< CTL_DSC_ARC4_LOADSTATE_LSB)
end_define

begin_comment
comment|/* #define CTRL_DSC_ARC4_KEYLEN */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_KEYLEN_LSB
value|35
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_KEYLEN_BITS
value|FIVE_BITS
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ARC4_KEYLEN_MASK
value|(CTL_DSC_ARC4_KEYLEN_BITS<< CTL_DSC_ARC4_KEYLEN_LSB)
end_define

begin_comment
comment|/* #define CTL_DSC_CPHR  (cipher) */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_CPHR_BYPASS
value|0
end_define

begin_comment
comment|/* undefined */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_CPHR_DES
value|1
end_define

begin_define
define|#
directive|define
name|CTL_DSC_CPHR_3DES
value|2
end_define

begin_define
define|#
directive|define
name|CTL_DSC_CPHR_AES128
value|3
end_define

begin_define
define|#
directive|define
name|CTL_DSC_CPHR_AES192
value|4
end_define

begin_define
define|#
directive|define
name|CTL_DSC_CPHR_AES256
value|5
end_define

begin_define
define|#
directive|define
name|CTL_DSC_CPHR_ARC4
value|6
end_define

begin_define
define|#
directive|define
name|CTL_DSC_CPHR_KASUMI_F8
value|7
end_define

begin_define
define|#
directive|define
name|CTL_DSC_CPHR_LSB
value|32
end_define

begin_define
define|#
directive|define
name|CTL_DSC_CPHR_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|CTL_DSC_CPHR_MASK
value|(CTL_DSC_CPHR_BITS<< CTL_DSC_CPHR_LSB)
end_define

begin_comment
comment|/* #define CTL_DSC_MODE  */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_MODE_ECB
value|0
end_define

begin_define
define|#
directive|define
name|CTL_DSC_MODE_CBC
value|1
end_define

begin_define
define|#
directive|define
name|CTL_DSC_MODE_CFB
value|2
end_define

begin_define
define|#
directive|define
name|CTL_DSC_MODE_OFB
value|3
end_define

begin_define
define|#
directive|define
name|CTL_DSC_MODE_CTR
value|4
end_define

begin_define
define|#
directive|define
name|CTL_DSC_MODE_F8
value|5
end_define

begin_define
define|#
directive|define
name|CTL_DSC_MODE_LSB
value|29
end_define

begin_define
define|#
directive|define
name|CTL_DSC_MODE_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|CTL_DSC_MODE_MASK
value|(CTL_DSC_MODE_BITS<< CTL_DSC_MODE_LSB)
end_define

begin_comment
comment|/* #define CTL_DSC_ICPHR */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_ICPHR_OKY
value|0
end_define

begin_comment
comment|/* Old Keys */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_ICPHR_NKY
value|1
end_define

begin_comment
comment|/* New Keys */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_ICPHR_LSB
value|28
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ICPHR_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|CTL_DSC_ICPHR_MASK
value|(CTL_DSC_ICPHR_BITS<< CTL_DSC_ICPHR_LSB)
end_define

begin_comment
comment|/* #define CTL_DSC_HASHHI */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_HASHHI_LSB
value|24
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HASHHI_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HASHHI_MASK
value|(CTL_DSC_HASHHI_BITS<< CTL_DSC_HASHHI_LSB)
end_define

begin_comment
comment|/* #define CTL_DSC_HMAC */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_HMAC_OFF
value|0
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HMAC_ON
value|1
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HMAC_LSB
value|23
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HMAC_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HMAC_MASK
value|(CTL_DSC_HMAC_BITS<< CTL_DSC_HMAC_LSB)
end_define

begin_comment
comment|/* #define CTL_DSC_HASH */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_HASH_NOP
value|0
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HASH_MD5
value|1
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HASH_SHA1
value|2
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HASH_SHA256
value|3
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HASH_SHA384
value|4
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HASH_SHA512
value|5
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HASH_GCM
value|6
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HASH_KASUMI_F9
value|7
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HASH_LSB
value|21
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HASH_BITS
value|TWO_BITS
end_define

begin_define
define|#
directive|define
name|CTL_DSC_HASH_MASK
value|(CTL_DSC_HASH_BITS<< CTL_DSC_HASH_LSB)
end_define

begin_comment
comment|/* #define CTL_DSC_IHASH */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_IHASH_OLD
value|0
end_define

begin_define
define|#
directive|define
name|CTL_DSC_IHASH_NEW
value|1
end_define

begin_define
define|#
directive|define
name|CTL_DSC_IHASH_LSB
value|20
end_define

begin_define
define|#
directive|define
name|CTL_DSC_IHASH_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|CTL_DSC_IHASH_MASK
value|(CTL_DSC_IHASH_BITS<< CTL_DSC_IHASH_LSB)
end_define

begin_comment
comment|/* #define CTL_DSC_CKSUM */
end_comment

begin_define
define|#
directive|define
name|CTL_DSC_CKSUM_NOP
value|0
end_define

begin_define
define|#
directive|define
name|CTL_DSC_CKSUM_IP
value|1
end_define

begin_define
define|#
directive|define
name|CTL_DSC_CKSUM_LSB
value|16
end_define

begin_define
define|#
directive|define
name|CTL_DSC_CKSUM_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|CTL_DSC_CKSUM_MASK
value|(CTL_DSC_CKSUM_BITS<< CTL_DSC_CKSUM_LSB)
end_define

begin_comment
comment|/*  * Component strcts and unions defining CipherHashInfo_u  */
end_comment

begin_comment
comment|/* AES256, (ECB, CBC, OFB, CTR, CFB), HMAC (MD5, SHA-1, SHA-256)      - 96  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES256HMAC_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
block|}
name|AES256HMAC_t
operator|,
typedef|*
name|AES256HMAC_pt
typedef|;
end_typedef

begin_comment
comment|/* AES256, (ECB, CBC, OFB, CTR, CFB), HMAC (SHA-384, SHA-512)      - 160  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES256HMAC2_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
name|uint64_t
name|hmacKey8
decl_stmt|;
name|uint64_t
name|hmacKey9
decl_stmt|;
name|uint64_t
name|hmacKey10
decl_stmt|;
name|uint64_t
name|hmacKey11
decl_stmt|;
name|uint64_t
name|hmacKey12
decl_stmt|;
name|uint64_t
name|hmacKey13
decl_stmt|;
name|uint64_t
name|hmacKey14
decl_stmt|;
name|uint64_t
name|hmacKey15
decl_stmt|;
block|}
name|AES256HMAC2_t
operator|,
typedef|*
name|AES256HMAC2_pt
typedef|;
end_typedef

begin_comment
comment|/* AES256, (ECB, CBC, OFB, CTR, CFB), GCM      - 56  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES256GCM_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|GCMH0
decl_stmt|;
name|uint64_t
name|GCMH1
decl_stmt|;
name|uint64_t
name|GCMSCI
decl_stmt|;
block|}
name|AES256GCM_t
operator|,
typedef|*
name|AES256GCM_pt
typedef|;
end_typedef

begin_comment
comment|/* AES256, (ECB, CBC, OFB, CTR, CFB), F9      - 56  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES256F9_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|authKey0
decl_stmt|;
name|uint64_t
name|authKey1
decl_stmt|;
block|}
name|AES256F9_t
operator|,
typedef|*
name|AES256F9_pt
typedef|;
end_typedef

begin_comment
comment|/* AES256, (ECB, CBC, OFB, CTR, CFB), Non-HMAC (MD5, SHA-1, SHA-256)  - 32  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES256_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
block|}
name|AES256_t
operator|,
typedef|*
name|AES256_pt
typedef|;
end_typedef

begin_comment
comment|/* All AES192 possibilities */
end_comment

begin_comment
comment|/* AES192, (ECB, CBC, OFB, CTR, CFB), HMAC (MD5, SHA-1, SHA-192)      - 88  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES192HMAC_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
block|}
name|AES192HMAC_t
operator|,
typedef|*
name|AES192HMAC_pt
typedef|;
end_typedef

begin_comment
comment|/* AES192, (ECB, CBC, OFB, CTR, CFB), HMAC (SHA-384, SHA-512)      - 152  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES192HMAC2_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
name|uint64_t
name|hmacKey8
decl_stmt|;
name|uint64_t
name|hmacKey9
decl_stmt|;
name|uint64_t
name|hmacKey10
decl_stmt|;
name|uint64_t
name|hmacKey11
decl_stmt|;
name|uint64_t
name|hmacKey12
decl_stmt|;
name|uint64_t
name|hmacKey13
decl_stmt|;
name|uint64_t
name|hmacKey14
decl_stmt|;
name|uint64_t
name|hmacKey15
decl_stmt|;
block|}
name|AES192HMAC2_t
operator|,
typedef|*
name|AES192HMAC2_pt
typedef|;
end_typedef

begin_comment
comment|/* AES192, (ECB, CBC, OFB, CTR, CFB), GCM      - 48  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES192GCM_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|GCMH0
decl_stmt|;
name|uint64_t
name|GCMH1
decl_stmt|;
name|uint64_t
name|GCMSCI
decl_stmt|;
block|}
name|AES192GCM_t
operator|,
typedef|*
name|AES192GCM_pt
typedef|;
end_typedef

begin_comment
comment|/* AES192, (ECB, CBC, OFB, CTR, CFB), F9      - 48  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES192F9_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|authKey0
decl_stmt|;
name|uint64_t
name|authKey1
decl_stmt|;
block|}
name|AES192F9_t
operator|,
typedef|*
name|AES192F9_pt
typedef|;
end_typedef

begin_comment
comment|/* AES192, (ECB, CBC, OFB, CTR, CFB), Non-HMAC (MD5, SHA-1, SHA-192)  - 24  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES192_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
block|}
name|AES192_t
operator|,
typedef|*
name|AES192_pt
typedef|;
end_typedef

begin_comment
comment|/* All AES128 possibilities */
end_comment

begin_comment
comment|/* AES128, (ECB, CBC, OFB, CTR, CFB), HMAC (MD5, SHA-1, SHA-128)      - 80  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES128HMAC_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
block|}
name|AES128HMAC_t
operator|,
typedef|*
name|AES128HMAC_pt
typedef|;
end_typedef

begin_comment
comment|/* AES128, (ECB, CBC, OFB, CTR, CFB), HMAC (SHA-384, SHA-612)      - 144  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES128HMAC2_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
name|uint64_t
name|hmacKey8
decl_stmt|;
name|uint64_t
name|hmacKey9
decl_stmt|;
name|uint64_t
name|hmacKey10
decl_stmt|;
name|uint64_t
name|hmacKey11
decl_stmt|;
name|uint64_t
name|hmacKey12
decl_stmt|;
name|uint64_t
name|hmacKey13
decl_stmt|;
name|uint64_t
name|hmacKey14
decl_stmt|;
name|uint64_t
name|hmacKey15
decl_stmt|;
block|}
name|AES128HMAC2_t
operator|,
typedef|*
name|AES128HMAC2_pt
typedef|;
end_typedef

begin_comment
comment|/* AES128, (ECB, CBC, OFB, CTR, CFB), GCM      - 40  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES128GCM_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|GCMH0
decl_stmt|;
name|uint64_t
name|GCMH1
decl_stmt|;
name|uint64_t
name|GCMSCI
decl_stmt|;
block|}
name|AES128GCM_t
operator|,
typedef|*
name|AES128GCM_pt
typedef|;
end_typedef

begin_comment
comment|/* AES128, (ECB, CBC, OFB, CTR, CFB), F9      - 48  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES128F9_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|authKey0
decl_stmt|;
name|uint64_t
name|authKey1
decl_stmt|;
block|}
name|AES128F9_t
operator|,
typedef|*
name|AES128F9_pt
typedef|;
end_typedef

begin_comment
comment|/* AES128, (ECB, CBC, OFB, CTR, CFB), Non-HMAC (MD5, SHA-1, SHA-128)  - 16  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES128_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
block|}
name|AES128_t
operator|,
typedef|*
name|AES128_pt
typedef|;
end_typedef

begin_comment
comment|/* AES128, (OFB F8), Non-HMAC (MD5, SHA-1, SHA-256)  - 32  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES128F8_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKeyMask0
decl_stmt|;
name|uint64_t
name|cipherKeyMask1
decl_stmt|;
block|}
name|AES128F8_t
operator|,
typedef|*
name|AES128F8_pt
typedef|;
end_typedef

begin_comment
comment|/* AES128, (OFB F8), HMAC (MD5, SHA-1, SHA-256)  - 96  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES128F8HMAC_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKeyMask0
decl_stmt|;
name|uint64_t
name|cipherKeyMask1
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
block|}
name|AES128F8HMAC_t
operator|,
typedef|*
name|AES128F8HMAC_pt
typedef|;
end_typedef

begin_comment
comment|/* AES128, (OFB F8), HMAC (SHA-384, SHA-512)  - 160  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES128F8HMAC2_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKeyMask0
decl_stmt|;
name|uint64_t
name|cipherKeyMask1
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
name|uint64_t
name|hmacKey8
decl_stmt|;
name|uint64_t
name|hmacKey9
decl_stmt|;
name|uint64_t
name|hmacKey10
decl_stmt|;
name|uint64_t
name|hmacKey11
decl_stmt|;
name|uint64_t
name|hmacKey12
decl_stmt|;
name|uint64_t
name|hmacKey13
decl_stmt|;
name|uint64_t
name|hmacKey14
decl_stmt|;
name|uint64_t
name|hmacKey15
decl_stmt|;
block|}
name|AES128F8HMAC2_t
operator|,
typedef|*
name|AES128F8HMAC2_pt
typedef|;
end_typedef

begin_comment
comment|/* AES192, (OFB F8), Non-HMAC (MD5, SHA-1, SHA-256)  - 48  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES192F8_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKeyMask0
decl_stmt|;
name|uint64_t
name|cipherKeyMask1
decl_stmt|;
name|uint64_t
name|cipherKeyMask2
decl_stmt|;
block|}
name|AES192F8_t
operator|,
typedef|*
name|AES192F8_pt
typedef|;
end_typedef

begin_comment
comment|/* AES192, (OFB F8), HMAC (MD5, SHA-1, SHA-256)  - 112 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES192F8HMAC_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKeyMask0
decl_stmt|;
name|uint64_t
name|cipherKeyMask1
decl_stmt|;
name|uint64_t
name|cipherKeyMask2
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
block|}
name|AES192F8HMAC_t
operator|,
typedef|*
name|AES192F8HMAC_pt
typedef|;
end_typedef

begin_comment
comment|/* AES192, (OFB F8), HMAC (SHA-384, SHA-512)  - 176 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES192F8HMAC2_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKeyMask0
decl_stmt|;
name|uint64_t
name|cipherKeyMask1
decl_stmt|;
name|uint64_t
name|cipherKeyMask2
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
name|uint64_t
name|hmacKey8
decl_stmt|;
name|uint64_t
name|hmacKey9
decl_stmt|;
name|uint64_t
name|hmacKey10
decl_stmt|;
name|uint64_t
name|hmacKey11
decl_stmt|;
name|uint64_t
name|hmacKey12
decl_stmt|;
name|uint64_t
name|hmacKey13
decl_stmt|;
name|uint64_t
name|hmacKey14
decl_stmt|;
name|uint64_t
name|hmacKey15
decl_stmt|;
block|}
name|AES192F8HMAC2_t
operator|,
typedef|*
name|AES192F8HMAC2_pt
typedef|;
end_typedef

begin_comment
comment|/* AES256, (OFB F8), Non-HMAC (MD5, SHA-1, SHA-256)  - 64  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES256F8_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|cipherKeyMask0
decl_stmt|;
name|uint64_t
name|cipherKeyMask1
decl_stmt|;
name|uint64_t
name|cipherKeyMask2
decl_stmt|;
name|uint64_t
name|cipherKeyMask3
decl_stmt|;
block|}
name|AES256F8_t
operator|,
typedef|*
name|AES256F8_pt
typedef|;
end_typedef

begin_comment
comment|/* AES256, (OFB F8), HMAC (MD5, SHA-1, SHA-256)  - 128  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES256F8HMAC_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|cipherKeyMask0
decl_stmt|;
name|uint64_t
name|cipherKeyMask1
decl_stmt|;
name|uint64_t
name|cipherKeyMask2
decl_stmt|;
name|uint64_t
name|cipherKeyMask3
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
block|}
name|AES256F8HMAC_t
operator|,
typedef|*
name|AES256F8HMAC_pt
typedef|;
end_typedef

begin_comment
comment|/* AES256, (OFB F8), HMAC (SHA-384, SHA-512)  - 192  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES256F8HMAC2_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|cipherKeyMask0
decl_stmt|;
name|uint64_t
name|cipherKeyMask1
decl_stmt|;
name|uint64_t
name|cipherKeyMask2
decl_stmt|;
name|uint64_t
name|cipherKeyMask3
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
name|uint64_t
name|hmacKey8
decl_stmt|;
name|uint64_t
name|hmacKey9
decl_stmt|;
name|uint64_t
name|hmacKey10
decl_stmt|;
name|uint64_t
name|hmacKey11
decl_stmt|;
name|uint64_t
name|hmacKey12
decl_stmt|;
name|uint64_t
name|hmacKey13
decl_stmt|;
name|uint64_t
name|hmacKey14
decl_stmt|;
name|uint64_t
name|hmacKey15
decl_stmt|;
block|}
name|AES256F8HMAC2_t
operator|,
typedef|*
name|AES256F8HMAC2_pt
typedef|;
end_typedef

begin_comment
comment|/* AES256, (F8), GCM      - 40  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES128F8GCM_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|GCMH0
decl_stmt|;
name|uint64_t
name|GCMH1
decl_stmt|;
name|uint64_t
name|GCMSCI
decl_stmt|;
block|}
name|AES128F8GCM_t
operator|,
typedef|*
name|AES128F8GCM_pt
typedef|;
end_typedef

begin_comment
comment|/* AES256, (F8), GCM      - 48  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES192F8GCM_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|GCMH0
decl_stmt|;
name|uint64_t
name|GCMH1
decl_stmt|;
name|uint64_t
name|GCMSCI
decl_stmt|;
block|}
name|AES192F8GCM_t
operator|,
typedef|*
name|AES192F8GCM_pt
typedef|;
end_typedef

begin_comment
comment|/* AES256, (F8), GCM      - 56  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES256F8GCM_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|GCMH0
decl_stmt|;
name|uint64_t
name|GCMH1
decl_stmt|;
name|uint64_t
name|GCMSCI
decl_stmt|;
block|}
name|AES256F8GCM_t
operator|,
typedef|*
name|AES256F8GCM_pt
typedef|;
end_typedef

begin_comment
comment|/* AES256, (F8), F9      - 40  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES128F8F9_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|authKey0
decl_stmt|;
name|uint64_t
name|authKey1
decl_stmt|;
block|}
name|AES128F8F9_t
operator|,
typedef|*
name|AES128F8F9_pt
typedef|;
end_typedef

begin_comment
comment|/* AES256, (F8), F9      - 48  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES192F8F9_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|authKey0
decl_stmt|;
name|uint64_t
name|authKey1
decl_stmt|;
block|}
name|AES192F8F9_t
operator|,
typedef|*
name|AES192F8F9_pt
typedef|;
end_typedef

begin_comment
comment|/* AES256F8, (F8), F9      - 56  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AES256F8F9_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|authKey0
decl_stmt|;
name|uint64_t
name|authKey1
decl_stmt|;
block|}
name|AES256F8F9_t
operator|,
typedef|*
name|AES256F8F9_pt
typedef|;
end_typedef

begin_comment
comment|/* All DES possibilities */
end_comment

begin_comment
comment|/* DES, (ECB, CBC), HMAC (MD5, SHA-1, SHA-128)              - 72  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|DESHMAC_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
block|}
name|DESHMAC_t
operator|,
typedef|*
name|DESHMAC_pt
typedef|;
end_typedef

begin_comment
comment|/* DES, (ECB, CBC), HMAC (SHA-384, SHA-512)              - 136  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|DESHMAC2_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
name|uint64_t
name|hmacKey8
decl_stmt|;
name|uint64_t
name|hmacKey9
decl_stmt|;
name|uint64_t
name|hmacKey10
decl_stmt|;
name|uint64_t
name|hmacKey11
decl_stmt|;
name|uint64_t
name|hmacKey12
decl_stmt|;
name|uint64_t
name|hmacKey13
decl_stmt|;
name|uint64_t
name|hmacKey14
decl_stmt|;
name|uint64_t
name|hmacKey15
decl_stmt|;
block|}
name|DESHMAC2_t
operator|,
typedef|*
name|DESHMAC2_pt
typedef|;
end_typedef

begin_comment
comment|/* DES, (ECB, CBC), GCM              - 32  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|DESGCM_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|GCMH0
decl_stmt|;
name|uint64_t
name|GCMH1
decl_stmt|;
name|uint64_t
name|GCMSCI
decl_stmt|;
block|}
name|DESGCM_t
operator|,
typedef|*
name|DESGCM_pt
typedef|;
end_typedef

begin_comment
comment|/* DES, (ECB, CBC), F9              - 32  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|DESF9_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|authKey0
decl_stmt|;
name|uint64_t
name|authKey1
decl_stmt|;
block|}
name|DESF9_t
operator|,
typedef|*
name|DESF9_pt
typedef|;
end_typedef

begin_comment
comment|/* DES, (ECB, CBC), Non-HMAC (MD5, SHA-1, SHA-128)          - 9   bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|DES_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
block|}
name|DES_t
operator|,
typedef|*
name|DES_pt
typedef|;
end_typedef

begin_comment
comment|/* All 3DES possibilities */
end_comment

begin_comment
comment|/* 3DES, (ECB, CBC), HMAC (MD5, SHA-1, SHA-128)             - 88  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|DES3HMAC_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
block|}
name|DES3HMAC_t
operator|,
typedef|*
name|DES3HMAC_pt
typedef|;
end_typedef

begin_comment
comment|/* 3DES, (ECB, CBC), HMAC (SHA-384, SHA-512)             - 152  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|DES3HMAC2_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
name|uint64_t
name|hmacKey8
decl_stmt|;
name|uint64_t
name|hmacKey9
decl_stmt|;
name|uint64_t
name|hmacKey10
decl_stmt|;
name|uint64_t
name|hmacKey11
decl_stmt|;
name|uint64_t
name|hmacKey12
decl_stmt|;
name|uint64_t
name|hmacKey13
decl_stmt|;
name|uint64_t
name|hmacKey14
decl_stmt|;
name|uint64_t
name|hmacKey15
decl_stmt|;
block|}
name|DES3HMAC2_t
operator|,
typedef|*
name|DES3HMAC2_pt
typedef|;
end_typedef

begin_comment
comment|/* 3DES, (ECB, CBC), GCM             - 48  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|DES3GCM_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|GCMH0
decl_stmt|;
name|uint64_t
name|GCMH1
decl_stmt|;
name|uint64_t
name|GCMSCI
decl_stmt|;
block|}
name|DES3GCM_t
operator|,
typedef|*
name|DES3GCM_pt
typedef|;
end_typedef

begin_comment
comment|/* 3DES, (ECB, CBC), GCM             - 48  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|DES3F9_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|authKey0
decl_stmt|;
name|uint64_t
name|authKey1
decl_stmt|;
block|}
name|DES3F9_t
operator|,
typedef|*
name|DES3F9_pt
typedef|;
end_typedef

begin_comment
comment|/* 3DES, (ECB, CBC), Non-HMAC (MD5, SHA-1, SHA-128)         - 24  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|DES3_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
block|}
name|DES3_t
operator|,
typedef|*
name|DES3_pt
typedef|;
end_typedef

begin_comment
comment|/* HMAC only - no cipher */
end_comment

begin_comment
comment|/* HMAC (MD5, SHA-1, SHA-128)                               - 64  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|HMAC_s
block|{
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
block|}
name|HMAC_t
operator|,
typedef|*
name|HMAC_pt
typedef|;
end_typedef

begin_comment
comment|/* HMAC (SHA-384, SHA-512)                               - 128  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|HMAC2_s
block|{
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
name|uint64_t
name|hmacKey8
decl_stmt|;
name|uint64_t
name|hmacKey9
decl_stmt|;
name|uint64_t
name|hmacKey10
decl_stmt|;
name|uint64_t
name|hmacKey11
decl_stmt|;
name|uint64_t
name|hmacKey12
decl_stmt|;
name|uint64_t
name|hmacKey13
decl_stmt|;
name|uint64_t
name|hmacKey14
decl_stmt|;
name|uint64_t
name|hmacKey15
decl_stmt|;
block|}
name|HMAC2_t
operator|,
typedef|*
name|HMAC2_pt
typedef|;
end_typedef

begin_comment
comment|/* GCM                               - 24  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|GCM_s
block|{
name|uint64_t
name|GCMH0
decl_stmt|;
name|uint64_t
name|GCMH1
decl_stmt|;
name|uint64_t
name|GCMSCI
decl_stmt|;
block|}
name|GCM_t
operator|,
typedef|*
name|GCM_pt
typedef|;
end_typedef

begin_comment
comment|/* F9                               - 24  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|F9_s
block|{
name|uint64_t
name|authKey0
decl_stmt|;
name|uint64_t
name|authKey1
decl_stmt|;
block|}
name|F9_t
operator|,
typedef|*
name|F9_pt
typedef|;
end_typedef

begin_comment
comment|/* All ARC4 possibilities */
end_comment

begin_comment
comment|/* ARC4, HMAC (MD5, SHA-1, SHA-256)      - 96 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ARC4HMAC_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
block|}
name|ARC4HMAC_t
operator|,
typedef|*
name|ARC4HMAC_pt
typedef|;
end_typedef

begin_comment
comment|/* ARC4, HMAC (SHA-384, SHA-512)      - 160 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ARC4HMAC2_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
name|uint64_t
name|hmacKey8
decl_stmt|;
name|uint64_t
name|hmacKey9
decl_stmt|;
name|uint64_t
name|hmacKey10
decl_stmt|;
name|uint64_t
name|hmacKey11
decl_stmt|;
name|uint64_t
name|hmacKey12
decl_stmt|;
name|uint64_t
name|hmacKey13
decl_stmt|;
name|uint64_t
name|hmacKey14
decl_stmt|;
name|uint64_t
name|hmacKey15
decl_stmt|;
block|}
name|ARC4HMAC2_t
operator|,
typedef|*
name|ARC4HMAC2_pt
typedef|;
end_typedef

begin_comment
comment|/* ARC4, GCM      - 56 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ARC4GCM_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|GCMH0
decl_stmt|;
name|uint64_t
name|GCMH1
decl_stmt|;
name|uint64_t
name|GCMSCI
decl_stmt|;
block|}
name|ARC4GCM_t
operator|,
typedef|*
name|ARC4GCM_pt
typedef|;
end_typedef

begin_comment
comment|/* ARC4, F9      - 56 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ARC4F9_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|authKey0
decl_stmt|;
name|uint64_t
name|authKey1
decl_stmt|;
block|}
name|ARC4F9_t
operator|,
typedef|*
name|ARC4F9_pt
typedef|;
end_typedef

begin_comment
comment|/* ARC4, HMAC (MD5, SHA-1, SHA-256)      - 408 bytes (not including 8 bytes from instruction) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ARC4StateHMAC_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
name|uint64_t
name|PAD0
decl_stmt|;
name|uint64_t
name|PAD1
decl_stmt|;
name|uint64_t
name|PAD2
decl_stmt|;
name|uint64_t
name|Arc4SboxData0
decl_stmt|;
name|uint64_t
name|Arc4SboxData1
decl_stmt|;
name|uint64_t
name|Arc4SboxData2
decl_stmt|;
name|uint64_t
name|Arc4SboxData3
decl_stmt|;
name|uint64_t
name|Arc4SboxData4
decl_stmt|;
name|uint64_t
name|Arc4SboxData5
decl_stmt|;
name|uint64_t
name|Arc4SboxData6
decl_stmt|;
name|uint64_t
name|Arc4SboxData7
decl_stmt|;
name|uint64_t
name|Arc4SboxData8
decl_stmt|;
name|uint64_t
name|Arc4SboxData9
decl_stmt|;
name|uint64_t
name|Arc4SboxData10
decl_stmt|;
name|uint64_t
name|Arc4SboxData11
decl_stmt|;
name|uint64_t
name|Arc4SboxData12
decl_stmt|;
name|uint64_t
name|Arc4SboxData13
decl_stmt|;
name|uint64_t
name|Arc4SboxData14
decl_stmt|;
name|uint64_t
name|Arc4SboxData15
decl_stmt|;
name|uint64_t
name|Arc4SboxData16
decl_stmt|;
name|uint64_t
name|Arc4SboxData17
decl_stmt|;
name|uint64_t
name|Arc4SboxData18
decl_stmt|;
name|uint64_t
name|Arc4SboxData19
decl_stmt|;
name|uint64_t
name|Arc4SboxData20
decl_stmt|;
name|uint64_t
name|Arc4SboxData21
decl_stmt|;
name|uint64_t
name|Arc4SboxData22
decl_stmt|;
name|uint64_t
name|Arc4SboxData23
decl_stmt|;
name|uint64_t
name|Arc4SboxData24
decl_stmt|;
name|uint64_t
name|Arc4SboxData25
decl_stmt|;
name|uint64_t
name|Arc4SboxData26
decl_stmt|;
name|uint64_t
name|Arc4SboxData27
decl_stmt|;
name|uint64_t
name|Arc4SboxData28
decl_stmt|;
name|uint64_t
name|Arc4SboxData29
decl_stmt|;
name|uint64_t
name|Arc4SboxData30
decl_stmt|;
name|uint64_t
name|Arc4SboxData31
decl_stmt|;
name|uint64_t
name|Arc4IJData
decl_stmt|;
name|uint64_t
name|PAD3
decl_stmt|;
name|uint64_t
name|PAD4
decl_stmt|;
name|uint64_t
name|PAD5
decl_stmt|;
block|}
name|ARC4StateHMAC_t
operator|,
typedef|*
name|ARC4StateHMAC_pt
typedef|;
end_typedef

begin_comment
comment|/* ARC4, HMAC (SHA-384, SHA-512)      - 480 bytes (not including 8 bytes from instruction) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ARC4StateHMAC2_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
name|uint64_t
name|hmacKey8
decl_stmt|;
name|uint64_t
name|hmacKey9
decl_stmt|;
name|uint64_t
name|hmacKey10
decl_stmt|;
name|uint64_t
name|hmacKey11
decl_stmt|;
name|uint64_t
name|hmacKey12
decl_stmt|;
name|uint64_t
name|hmacKey13
decl_stmt|;
name|uint64_t
name|hmacKey14
decl_stmt|;
name|uint64_t
name|hmacKey15
decl_stmt|;
name|uint64_t
name|PAD0
decl_stmt|;
name|uint64_t
name|PAD1
decl_stmt|;
name|uint64_t
name|PAD2
decl_stmt|;
name|uint64_t
name|Arc4SboxData0
decl_stmt|;
name|uint64_t
name|Arc4SboxData1
decl_stmt|;
name|uint64_t
name|Arc4SboxData2
decl_stmt|;
name|uint64_t
name|Arc4SboxData3
decl_stmt|;
name|uint64_t
name|Arc4SboxData4
decl_stmt|;
name|uint64_t
name|Arc4SboxData5
decl_stmt|;
name|uint64_t
name|Arc4SboxData6
decl_stmt|;
name|uint64_t
name|Arc4SboxData7
decl_stmt|;
name|uint64_t
name|Arc4SboxData8
decl_stmt|;
name|uint64_t
name|Arc4SboxData9
decl_stmt|;
name|uint64_t
name|Arc4SboxData10
decl_stmt|;
name|uint64_t
name|Arc4SboxData11
decl_stmt|;
name|uint64_t
name|Arc4SboxData12
decl_stmt|;
name|uint64_t
name|Arc4SboxData13
decl_stmt|;
name|uint64_t
name|Arc4SboxData14
decl_stmt|;
name|uint64_t
name|Arc4SboxData15
decl_stmt|;
name|uint64_t
name|Arc4SboxData16
decl_stmt|;
name|uint64_t
name|Arc4SboxData17
decl_stmt|;
name|uint64_t
name|Arc4SboxData18
decl_stmt|;
name|uint64_t
name|Arc4SboxData19
decl_stmt|;
name|uint64_t
name|Arc4SboxData20
decl_stmt|;
name|uint64_t
name|Arc4SboxData21
decl_stmt|;
name|uint64_t
name|Arc4SboxData22
decl_stmt|;
name|uint64_t
name|Arc4SboxData23
decl_stmt|;
name|uint64_t
name|Arc4SboxData24
decl_stmt|;
name|uint64_t
name|Arc4SboxData25
decl_stmt|;
name|uint64_t
name|Arc4SboxData26
decl_stmt|;
name|uint64_t
name|Arc4SboxData27
decl_stmt|;
name|uint64_t
name|Arc4SboxData28
decl_stmt|;
name|uint64_t
name|Arc4SboxData29
decl_stmt|;
name|uint64_t
name|Arc4SboxData30
decl_stmt|;
name|uint64_t
name|Arc4SboxData31
decl_stmt|;
name|uint64_t
name|Arc4IJData
decl_stmt|;
name|uint64_t
name|PAD3
decl_stmt|;
name|uint64_t
name|PAD4
decl_stmt|;
name|uint64_t
name|PAD5
decl_stmt|;
block|}
name|ARC4StateHMAC2_t
operator|,
typedef|*
name|ARC4StateHMAC2_pt
typedef|;
end_typedef

begin_comment
comment|/* ARC4, GCM      - 408 bytes (not including 8 bytes from instruction) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ARC4StateGCM_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|GCMH0
decl_stmt|;
name|uint64_t
name|GCMH1
decl_stmt|;
name|uint64_t
name|GCMSCI
decl_stmt|;
name|uint64_t
name|PAD0
decl_stmt|;
name|uint64_t
name|PAD1
decl_stmt|;
name|uint64_t
name|PAD2
decl_stmt|;
name|uint64_t
name|PAD3
decl_stmt|;
name|uint64_t
name|PAD4
decl_stmt|;
name|uint64_t
name|PAD5
decl_stmt|;
name|uint64_t
name|PAD6
decl_stmt|;
name|uint64_t
name|PAD7
decl_stmt|;
name|uint64_t
name|Arc4SboxData0
decl_stmt|;
name|uint64_t
name|Arc4SboxData1
decl_stmt|;
name|uint64_t
name|Arc4SboxData2
decl_stmt|;
name|uint64_t
name|Arc4SboxData3
decl_stmt|;
name|uint64_t
name|Arc4SboxData4
decl_stmt|;
name|uint64_t
name|Arc4SboxData5
decl_stmt|;
name|uint64_t
name|Arc4SboxData6
decl_stmt|;
name|uint64_t
name|Arc4SboxData7
decl_stmt|;
name|uint64_t
name|Arc4SboxData8
decl_stmt|;
name|uint64_t
name|Arc4SboxData9
decl_stmt|;
name|uint64_t
name|Arc4SboxData10
decl_stmt|;
name|uint64_t
name|Arc4SboxData11
decl_stmt|;
name|uint64_t
name|Arc4SboxData12
decl_stmt|;
name|uint64_t
name|Arc4SboxData13
decl_stmt|;
name|uint64_t
name|Arc4SboxData14
decl_stmt|;
name|uint64_t
name|Arc4SboxData15
decl_stmt|;
name|uint64_t
name|Arc4SboxData16
decl_stmt|;
name|uint64_t
name|Arc4SboxData17
decl_stmt|;
name|uint64_t
name|Arc4SboxData18
decl_stmt|;
name|uint64_t
name|Arc4SboxData19
decl_stmt|;
name|uint64_t
name|Arc4SboxData20
decl_stmt|;
name|uint64_t
name|Arc4SboxData21
decl_stmt|;
name|uint64_t
name|Arc4SboxData22
decl_stmt|;
name|uint64_t
name|Arc4SboxData23
decl_stmt|;
name|uint64_t
name|Arc4SboxData24
decl_stmt|;
name|uint64_t
name|Arc4SboxData25
decl_stmt|;
name|uint64_t
name|Arc4SboxData26
decl_stmt|;
name|uint64_t
name|Arc4SboxData27
decl_stmt|;
name|uint64_t
name|Arc4SboxData28
decl_stmt|;
name|uint64_t
name|Arc4SboxData29
decl_stmt|;
name|uint64_t
name|Arc4SboxData30
decl_stmt|;
name|uint64_t
name|Arc4SboxData31
decl_stmt|;
name|uint64_t
name|Arc4IJData
decl_stmt|;
name|uint64_t
name|PAD8
decl_stmt|;
name|uint64_t
name|PAD9
decl_stmt|;
name|uint64_t
name|PAD10
decl_stmt|;
block|}
name|ARC4StateGCM_t
operator|,
typedef|*
name|ARC4StateGCM_pt
typedef|;
end_typedef

begin_comment
comment|/* ARC4, F9      - 408 bytes (not including 8 bytes from instruction) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ARC4StateF9_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|authKey0
decl_stmt|;
name|uint64_t
name|authKey1
decl_stmt|;
name|uint64_t
name|PAD0
decl_stmt|;
name|uint64_t
name|PAD1
decl_stmt|;
name|uint64_t
name|PAD2
decl_stmt|;
name|uint64_t
name|PAD3
decl_stmt|;
name|uint64_t
name|PAD4
decl_stmt|;
name|uint64_t
name|PAD5
decl_stmt|;
name|uint64_t
name|PAD6
decl_stmt|;
name|uint64_t
name|PAD7
decl_stmt|;
name|uint64_t
name|PAD8
decl_stmt|;
name|uint64_t
name|Arc4SboxData0
decl_stmt|;
name|uint64_t
name|Arc4SboxData1
decl_stmt|;
name|uint64_t
name|Arc4SboxData2
decl_stmt|;
name|uint64_t
name|Arc4SboxData3
decl_stmt|;
name|uint64_t
name|Arc4SboxData4
decl_stmt|;
name|uint64_t
name|Arc4SboxData5
decl_stmt|;
name|uint64_t
name|Arc4SboxData6
decl_stmt|;
name|uint64_t
name|Arc4SboxData7
decl_stmt|;
name|uint64_t
name|Arc4SboxData8
decl_stmt|;
name|uint64_t
name|Arc4SboxData9
decl_stmt|;
name|uint64_t
name|Arc4SboxData10
decl_stmt|;
name|uint64_t
name|Arc4SboxData11
decl_stmt|;
name|uint64_t
name|Arc4SboxData12
decl_stmt|;
name|uint64_t
name|Arc4SboxData13
decl_stmt|;
name|uint64_t
name|Arc4SboxData14
decl_stmt|;
name|uint64_t
name|Arc4SboxData15
decl_stmt|;
name|uint64_t
name|Arc4SboxData16
decl_stmt|;
name|uint64_t
name|Arc4SboxData17
decl_stmt|;
name|uint64_t
name|Arc4SboxData18
decl_stmt|;
name|uint64_t
name|Arc4SboxData19
decl_stmt|;
name|uint64_t
name|Arc4SboxData20
decl_stmt|;
name|uint64_t
name|Arc4SboxData21
decl_stmt|;
name|uint64_t
name|Arc4SboxData22
decl_stmt|;
name|uint64_t
name|Arc4SboxData23
decl_stmt|;
name|uint64_t
name|Arc4SboxData24
decl_stmt|;
name|uint64_t
name|Arc4SboxData25
decl_stmt|;
name|uint64_t
name|Arc4SboxData26
decl_stmt|;
name|uint64_t
name|Arc4SboxData27
decl_stmt|;
name|uint64_t
name|Arc4SboxData28
decl_stmt|;
name|uint64_t
name|Arc4SboxData29
decl_stmt|;
name|uint64_t
name|Arc4SboxData30
decl_stmt|;
name|uint64_t
name|Arc4SboxData31
decl_stmt|;
name|uint64_t
name|Arc4IJData
decl_stmt|;
name|uint64_t
name|PAD9
decl_stmt|;
name|uint64_t
name|PAD10
decl_stmt|;
name|uint64_t
name|PAD11
decl_stmt|;
block|}
name|ARC4StateF9_t
operator|,
typedef|*
name|ARC4StateF9_pt
typedef|;
end_typedef

begin_comment
comment|/* ARC4, Non-HMAC (MD5, SHA-1, SHA-256)  - 32  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ARC4_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
block|}
name|ARC4_t
operator|,
typedef|*
name|ARC4_pt
typedef|;
end_typedef

begin_comment
comment|/* ARC4, Non-HMAC (MD5, SHA-1, SHA-256)  - 344  bytes (not including 8 bytes from instruction) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ARC4State_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|cipherKey2
decl_stmt|;
name|uint64_t
name|cipherKey3
decl_stmt|;
name|uint64_t
name|PAD0
decl_stmt|;
name|uint64_t
name|PAD1
decl_stmt|;
name|uint64_t
name|PAD2
decl_stmt|;
name|uint64_t
name|Arc4SboxData0
decl_stmt|;
name|uint64_t
name|Arc4SboxData1
decl_stmt|;
name|uint64_t
name|Arc4SboxData2
decl_stmt|;
name|uint64_t
name|Arc4SboxData3
decl_stmt|;
name|uint64_t
name|Arc4SboxData4
decl_stmt|;
name|uint64_t
name|Arc4SboxData5
decl_stmt|;
name|uint64_t
name|Arc4SboxData6
decl_stmt|;
name|uint64_t
name|Arc4SboxData7
decl_stmt|;
name|uint64_t
name|Arc4SboxData8
decl_stmt|;
name|uint64_t
name|Arc4SboxData9
decl_stmt|;
name|uint64_t
name|Arc4SboxData10
decl_stmt|;
name|uint64_t
name|Arc4SboxData11
decl_stmt|;
name|uint64_t
name|Arc4SboxData12
decl_stmt|;
name|uint64_t
name|Arc4SboxData13
decl_stmt|;
name|uint64_t
name|Arc4SboxData14
decl_stmt|;
name|uint64_t
name|Arc4SboxData15
decl_stmt|;
name|uint64_t
name|Arc4SboxData16
decl_stmt|;
name|uint64_t
name|Arc4SboxData17
decl_stmt|;
name|uint64_t
name|Arc4SboxData18
decl_stmt|;
name|uint64_t
name|Arc4SboxData19
decl_stmt|;
name|uint64_t
name|Arc4SboxData20
decl_stmt|;
name|uint64_t
name|Arc4SboxData21
decl_stmt|;
name|uint64_t
name|Arc4SboxData22
decl_stmt|;
name|uint64_t
name|Arc4SboxData23
decl_stmt|;
name|uint64_t
name|Arc4SboxData24
decl_stmt|;
name|uint64_t
name|Arc4SboxData25
decl_stmt|;
name|uint64_t
name|Arc4SboxData26
decl_stmt|;
name|uint64_t
name|Arc4SboxData27
decl_stmt|;
name|uint64_t
name|Arc4SboxData28
decl_stmt|;
name|uint64_t
name|Arc4SboxData29
decl_stmt|;
name|uint64_t
name|Arc4SboxData30
decl_stmt|;
name|uint64_t
name|Arc4SboxData31
decl_stmt|;
name|uint64_t
name|Arc4IJData
decl_stmt|;
name|uint64_t
name|PAD3
decl_stmt|;
name|uint64_t
name|PAD4
decl_stmt|;
name|uint64_t
name|PAD5
decl_stmt|;
block|}
name|ARC4State_t
operator|,
typedef|*
name|ARC4State_pt
typedef|;
end_typedef

begin_comment
comment|/* Kasumi f8  - 32  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|KASUMIF8_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
block|}
name|KASUMIF8_t
operator|,
typedef|*
name|KASUMIF8_pt
typedef|;
end_typedef

begin_comment
comment|/* Kasumi f8 + HMAC (MD5, SHA-1, SHA-256)  - 80  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|KASUMIF8HMAC_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
block|}
name|KASUMIF8HMAC_t
operator|,
typedef|*
name|KASUMIF8HMAC_pt
typedef|;
end_typedef

begin_comment
comment|/* Kasumi f8 + HMAC (SHA-384, SHA-512)  - 144 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|KASUMIF8HMAC2_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|hmacKey0
decl_stmt|;
name|uint64_t
name|hmacKey1
decl_stmt|;
name|uint64_t
name|hmacKey2
decl_stmt|;
name|uint64_t
name|hmacKey3
decl_stmt|;
name|uint64_t
name|hmacKey4
decl_stmt|;
name|uint64_t
name|hmacKey5
decl_stmt|;
name|uint64_t
name|hmacKey6
decl_stmt|;
name|uint64_t
name|hmacKey7
decl_stmt|;
name|uint64_t
name|hmacKey8
decl_stmt|;
name|uint64_t
name|hmacKey9
decl_stmt|;
name|uint64_t
name|hmacKey10
decl_stmt|;
name|uint64_t
name|hmacKey11
decl_stmt|;
name|uint64_t
name|hmacKey12
decl_stmt|;
name|uint64_t
name|hmacKey13
decl_stmt|;
name|uint64_t
name|hmacKey14
decl_stmt|;
name|uint64_t
name|hmacKey15
decl_stmt|;
block|}
name|KASUMIF8HMAC2_t
operator|,
typedef|*
name|KASUMIF8HMAC2_pt
typedef|;
end_typedef

begin_comment
comment|/* Kasumi f8 + GCM  - 144 bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|KASUMIF8GCM_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|GCMH0
decl_stmt|;
name|uint64_t
name|GCMH1
decl_stmt|;
name|uint64_t
name|GCMSCI
decl_stmt|;
block|}
name|KASUMIF8GCM_t
operator|,
typedef|*
name|KASUMIF8GCM_pt
typedef|;
end_typedef

begin_comment
comment|/* Kasumi f8 + f9  - 32  bytes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|KASUMIF8F9_s
block|{
name|uint64_t
name|cipherKey0
decl_stmt|;
name|uint64_t
name|cipherKey1
decl_stmt|;
name|uint64_t
name|authKey0
decl_stmt|;
name|uint64_t
name|authKey1
decl_stmt|;
block|}
name|KASUMIF8F9_t
operator|,
typedef|*
name|KASUMIF8F9_pt
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|CipherHashInfo_u
block|{
name|AES256HMAC_t
name|infoAES256HMAC
decl_stmt|;
name|AES256_t
name|infoAES256
decl_stmt|;
name|AES192HMAC_t
name|infoAES192HMAC
decl_stmt|;
name|AES192_t
name|infoAES192
decl_stmt|;
name|AES128HMAC_t
name|infoAES128HMAC
decl_stmt|;
name|AES128_t
name|infoAES128
decl_stmt|;
name|DESHMAC_t
name|infoDESHMAC
decl_stmt|;
name|DES_t
name|infoDES
decl_stmt|;
name|DES3HMAC_t
name|info3DESHMAC
decl_stmt|;
name|DES3_t
name|info3DES
decl_stmt|;
name|HMAC_t
name|infoHMAC
decl_stmt|;
comment|/* ARC4 */
name|ARC4HMAC_t
name|infoARC4HMAC
decl_stmt|;
name|ARC4StateHMAC_t
name|infoARC4StateHMAC
decl_stmt|;
name|ARC4_t
name|infoARC4
decl_stmt|;
name|ARC4State_t
name|infoARC4State
decl_stmt|;
comment|/* AES mode F8 */
name|AES256F8HMAC_t
name|infoAES256F8HMAC
decl_stmt|;
name|AES256F8_t
name|infoAES256F8
decl_stmt|;
name|AES192F8HMAC_t
name|infoAES192F8HMAC
decl_stmt|;
name|AES192F8_t
name|infoAES192F8
decl_stmt|;
name|AES128F8HMAC_t
name|infoAES128F8HMAC
decl_stmt|;
name|AES128F8_t
name|infoAES128F8
decl_stmt|;
comment|/* KASUMI F8 */
name|KASUMIF8HMAC_t
name|infoKASUMIF8HMAC
decl_stmt|;
name|KASUMIF8_t
name|infoKASUMIF8
decl_stmt|;
comment|/* GCM */
name|GCM_t
name|infoGCM
decl_stmt|;
name|AES256F8GCM_t
name|infoAES256F8GCM
decl_stmt|;
name|AES192F8GCM_t
name|infoAES192F8GCM
decl_stmt|;
name|AES128F8GCM_t
name|infoAES128F8GCM
decl_stmt|;
name|AES256GCM_t
name|infoAES256GCM
decl_stmt|;
name|AES192GCM_t
name|infoAES192GCM
decl_stmt|;
name|AES128GCM_t
name|infoAES128GCM
decl_stmt|;
name|DESGCM_t
name|infoDESGCM
decl_stmt|;
name|DES3GCM_t
name|info3DESGCM
decl_stmt|;
name|ARC4GCM_t
name|infoARC4GCM
decl_stmt|;
name|ARC4StateGCM_t
name|infoARC4StateGCM
decl_stmt|;
name|KASUMIF8GCM_t
name|infoKASUMIF8GCM
decl_stmt|;
comment|/* HMAC2 */
name|HMAC2_t
name|infoHMAC2
decl_stmt|;
name|AES256F8HMAC2_t
name|infoAES256F8HMAC2
decl_stmt|;
name|AES192F8HMAC2_t
name|infoAES192F8HMAC2
decl_stmt|;
name|AES128F8HMAC2_t
name|infoAES128F8HMAC2
decl_stmt|;
name|AES256HMAC2_t
name|infoAES256HMAC2
decl_stmt|;
name|AES192HMAC2_t
name|infoAES192HMAC2
decl_stmt|;
name|AES128HMAC2_t
name|infoAES128HMAC2
decl_stmt|;
name|DESHMAC2_t
name|infoDESHMAC2
decl_stmt|;
name|DES3HMAC2_t
name|info3DESHMAC2
decl_stmt|;
name|ARC4HMAC2_t
name|infoARC4HMAC2
decl_stmt|;
name|ARC4StateHMAC2_t
name|infoARC4StateHMAC2
decl_stmt|;
name|KASUMIF8HMAC2_t
name|infoKASUMIF8HMAC2
decl_stmt|;
comment|/* F9 */
name|F9_t
name|infoF9
decl_stmt|;
name|AES256F8F9_t
name|infoAES256F8F9
decl_stmt|;
name|AES192F8F9_t
name|infoAES192F8F9
decl_stmt|;
name|AES128F8F9_t
name|infoAES128F8F9
decl_stmt|;
name|AES256F9_t
name|infoAES256F9
decl_stmt|;
name|AES192F9_t
name|infoAES192F9
decl_stmt|;
name|AES128F9_t
name|infoAES128F9
decl_stmt|;
name|DESF9_t
name|infoDESF9
decl_stmt|;
name|DES3F9_t
name|info3DESF9
decl_stmt|;
name|ARC4F9_t
name|infoARC4F9
decl_stmt|;
name|ARC4StateF9_t
name|infoARC4StateF9
decl_stmt|;
name|KASUMIF8F9_t
name|infoKASUMIF8F9
decl_stmt|;
block|}
name|CipherHashInfo_t
operator|,
typedef|*
name|CipherHashInfo_pt
typedef|;
end_typedef

begin_comment
comment|/*   *   *    ControlDescriptor_s datastructure   *   */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ControlDescriptor_s
block|{
name|uint64_t
name|instruction
decl_stmt|;
name|CipherHashInfo_t
name|cipherHashInfo
decl_stmt|;
block|}
name|ControlDescriptor_t
operator|,
typedef|*
name|ControlDescriptor_pt
typedef|;
end_typedef

begin_comment
comment|/* **********************************************************************  *       PacketDescriptor_t  * **********************************************************************  */
end_comment

begin_comment
comment|/*       /--------------------------------------------\  *       |                                            |  *       |    New PacketDescriptor_s datastructure    |  *       |                                            |  *       \--------------------------------------------/  *  *  *  *       PacketDescriptor_t.srcLengthIVOffUseIVNext  *       ------------------------------------------  *  *           63           62      61             59    58        57    56       54  53           43   *  ------------------------------------------------------------------------------------------------  * || Load HMAC key || Pad Hash || Hash Byte Count || Next || Use IV || IV Offset || Packet length ||   ... CONT ...  *  ------------------------------------------------------------------------------------------------  *           1            1           3                1        1          3              11  *  *  *      42          41      40    39                  5     4          3       2  *      0  *  ----------------------------------------------------------------------------------------------------  * ||  NLHMAC || Break || Wait || Segment src address || SRTCP  || Reserved || Global src data offset ||  *  ----------------------------------------------------------------------------------------------------  *      1           1       1             35                1           1                  3  *  *  *  *             Load HMAC key           =        1'b0       Preserve old HMAC key stored in Auth engine (moot if HASH.HMAC == 0)  *                                              1'b1       Load HMAC key from ID registers at beginning of op  *                                                         If GCM is selected as authenticator, setting this bit  *                                                         will cause the H value from ID to be loaded to the engine  *                                                         If Kasumi F9 is selected as authenticator, setting this bit  *                                                         will cause the IK value from ID to be loaded to the engine.  *             Pad Hash                =        1'b0       HASH will assume the data was padded to be a multiple  *                                                         of 512 bits in length and that the last 64 bit word  *                                                         expresses the total datalength in bits seen by HASH engine  *                                              1'b1       The data was not padded to be a multiple of 512 bits in length;  *                                                         The Hash engine will do its own padding to generate the correct digest.  *                                                        Ignored by GCM (always does its own padding)  *             Hash Byte Count                             Number of BYTES on last 64-bit data word to use in digest calculation RELEVANT ONLY IF Pad Hash IS SET  *                                              3'b000     Use all 8  *                                              3'b001     Use first (MS) byte only (0-out rest), i.e., 0xddXXXXXXXXXXXXXX  *                                              3'b010     Use first 2 bytes only (0-out rest), i.e., 0xddddXXXXXXXXXXXX     ... etc  *             Next                    =        1'b0       Finish (return msg descriptor) at end of operation  *                                              1'b1       Grab the next PacketDescriptor (i.e. next cache-line) when the current is complete.  *                                                         This allows for fragmentation/defragmentation and processing of large (>16kB) packets.  *                                                         The sequence of adjacent PacketDescriptor acts as a contiguous linked list of  *                                                         pointers to the actual packets with Next==0 on the last PacketDescriptor to end processing.  *             Use IV                  =        1'b0       On first frag:           Use old IV  *                                                         On subsequent frags:     Do not write out to DST the (dword) offset data  *                                              1'b1       On first frag:           Use data @ Segment_address + IV_Offset as IV  *                                                         On subsequent frags:     Do write out to DST the (dword) offset data  *             IV Offset               =                   On first frag:           Offset IN NB OF 8 BYTE WORDS (dwords) from beginning of packet  *                                                                                  (i.e. (Potentially byte-shifted) Segment address) to cipher IV  *                                                         On subsequent frags:     Offset to beginning of data to process; data to offset won't   *                                                                                  be given to engines and will be written out to dst in the clear.  *                                                                                  ON SUBSEQUENT FRAGS, IV_Offset MAY NOT EXCEED 3; LARGER VALUES WILL CAUSE AN ERROR  *                                                                                  SEE ERROR CONDITIONS BELOW  *             Packet length           =                   Nb double words to stream in (Including Segment address->CP/IV/Auth/CkSum offsets)  *                                                         This is the total amount of data (x8 in bytes) read    (+1 dword if "Global src data offset" != 0)  *                                                         This is the total amount of data (x8 in bytes) written (+1 dword if "Global dst data offset" != 0, if Dst dword offset == 0)  *                                                         If Packet length == 11'h7ff and (Global src data offset != 0 or Global dst data offset != 0)  *                                                         the operation is aborted (no mem writes occur)  *                                                         and the "Insufficient Data To Cipher" error flag is raised  *             NLHMAC                  =                   No last to hmac. Setting this to 1 will prevent the transmission of the last DWORD  *                                                         to the authenticator, i.e., the DWORD before last will be designated as last for the purposes of authentication.  *             Break                   =                   Break a wait (see below) state - causes the operation to be flushed and free descriptor to be returned.  *                                                         Activated if DFetch blocked by Wait and Wait still active.  *                                                         AS OF 02/10/2005 THIS FEATURE IS EXPERIMENTAL  *             Wait                    =                   Setting that bit causes the operation to block in DFetch stage.  *                                                         DFetch will keep polling the memory location until the bit is reset at which time  *                                                         the pipe resumes normal operation. This feature is convenient for software dealing with fragmented packets.  *                                                         AS OF 02/10/2005 THIS FEATURE IS EXPERIMENTAL  *             Segment src address     =                   35 MSB of pointer to src data (i.e., cache-line aligned)  *             SRTCP                   =                   Bypass the cipher for the last 4 bytes of data, i.e. the last 4 bytes will be sent to memory  *                                                         and the authenticator in the clear. Applicable to last packet descriptor andlast frag only.  *                                                         This accommodates a requirement of SRTCP.  *             Global src data offset  =                   Nb BYTES to right-shift data by before presenting it to engines  *                                                         (0-7); allows realignment of byte-aligned, non-double-word aligned data  *  *       PacketDescriptor_t.dstDataSettings  *       ----------------------------------  *  *  *         63       62           60  59   58           56  55         54     53      52          41     40  *  ------------------------------------------------------------------------------------------------------------  * || CipherPrefix | Arc4ByteCount | E/D | Cipher_Offset || Hash_Offset | Hash_Src || CkSum_Offset | CkSum_Src ||   ... CONT ...  *  ------------------------------------------------------------------------------------------------------------  *         1                3         1          3               2           1             12            1  *<-----------------------CIPHER-----------------------><---------HASH-----------><-------CHECKSUM----------->  *  *  *             CipherPrefix            =                   128'b0 will be sent to the selected cipher  *             KEEP VALUE ON ALL FRAGS                     after the IV is loaded, before the actual data goes in.  *                                                         The result of that encryption (aka E(K, 0))will be stored  *                                                         locally and XOR-ed with the auth digest to create the final  *                                                         digest at the end of the auth OP:  *                                                         This is covered by the GCM spec  *                                                                   AesPrefix =  1'b1    -> Force   E=Cipher(K,0) before start of data encr.  *                                                                                        -> Digest ^= E  *                                                                   AesPrefix =  1'b0    -> Regular digest  *                                                         This flag is ignored if no cipher is chosen (Bypass condition)  *  X0         Arc4ByteCount           =                   Number of BYTES on last 64-bit data word to encrypt  *                                              3'b000     Encrypt all 8  *                                              3'b001     Encrypt first (MS) byte only i.e., 0xddXXXXXXXXXXXXXX  *                                              3'b010     Encrypt first 2 bytes only i.e., 0xddddXXXXXXXXXXXX     ... etc  *                                                         In reality, all are encrypted, however, the SBOX  *                                                         is not written past the last byte to encrypt  *             E/D                     =        1'b0       Decrypt  *                                              1'b1       Encrypt  *                                                         Overloaded to also mean IV byte offset for first frag  *             Cipher_Offset           =                   Nb of words between the first data segment   *                                                         and word on which to start cipher operation  *                                                         (64 BIT WORDS !!!)  *             Hash_Offset             =                   Nb of words between the first data segment  *                                                         and word on which to start hashing   *                                                         (64 bit words)  *             Hash_Src                =        1'b0       DMA channel  *                                              1'b1       Cipher if word count exceeded Cipher_Offset;   *                                                         DMA channel otherwise  *             CkSum_Offset            =                   Nb of words between the first data segment   *                                                         and word on which to start   *                                                         checksum calculation (32 BIT WORDS !!!)  *             CkSum_Src               =        1'b0       DMA channel  *                                              1'b1       Cipher if word count exceeded Cipher_Offset  *                                                         DMA channel otherwise  *             Cipher dst address      =                   35 MSB of pointer to dst location (i.e., cache-line aligned)  *             Dst dword offset        =                   Nb of double-words to left-shift data from spec'ed Cipher dst address before writing it to memory  *             Global dst data offset  =                   Nb BYTES to left-shift (double-word boundary aligned) data by before writing it to memory  *  *  *       PacketDescriptor_t.authDstNonceLow  *       ----------------------------------  *  *   63       40  39               5  4                0     *  -----------------------------------------------------  * || Nonce_Low || Auth_dst_address || Cipher_Offset_Hi ||  *  -----------------------------------------------------  *        24             35                    5  *  *  *  *             Nonce_Low         =                 Nonce[23:0] 24 least significant bits of 32-bit long nonce  *                                                 Used by AES in counter mode  *             Auth_dst_address  =                 35 MSB of pointer to authentication dst location (i.e., cache-line aligned)  * X0          Cipher_Offset_Hi  =                 On first frag:           5 MSB of 8-bit Cipher_offset; will be concatenated to  *                                                                          the top of PacketDescriptor_t.dstDataSettings.Cipher_Offset  *                                                 On subsequent frags:     Ignored  *  *  *       PacketDescriptor_t.ckSumDstNonceHiCFBMaskLLWMask  *       ------------------------------------------------  *  *  *   63              61  60                 58  57     56  55      48  47      40  39                5  4            0  *  -------------------------------------------------------------------------------------------------------------------  * || Hash_Byte_Offset || Packet length bytes || LLWMask || CFB_Mask || Nonce_Hi || CkSum_dst_address || IV_Offset_Hi ||  *  -------------------------------------------------------------------------------------------------------------------  *           3                    3                 2          8           8               35                 5  *  *  *                 Hash_Byte_Offset    =              On first frag:            Additional offset in bytes to be added to Hash_Offset  *                                                                              to obtain the full offset applied to the data before  *                                                                              submitting it to authenticator  *                                                    On subsequent frags:      Same  *                 Packet length bytes =              On one fragment payloads: Ignored (i.e. assumed to be 0, last dword used in its entirety)  *                                                    On fragments before last: Number of bytes on last fragment dword  *                                                    On last fragment:         Ignored (i.e. assumed to be 0, last dword used in its entirety)  *   LLWMask, aka, Last_long_word_mask =   2'b00      Give last 128 bit word from AES engine to auth/cksum/wrbbufer as is - applicable in AES CTR only  *                                         2'b11      Mask (zero-out) 32 least significant bits  *                                         2'b10      Mask 64 LSBs  *                                         2'b01      Mask 96 LSBs  *                                                    If the GCM authenticator is used, setting LLWMask to 2'b10 or 2'b01  *                                                    will also prevent the transmission of the last DWORD  *                                                    to the authenticator, i.e., the DWORD before last will  *                                                    be designated as last for the purposes of authentication.  *                 CFB_Mask            =              8 bit mask used by AES in CFB mode  *                                                    In CTR mode:  *                                                         CFB_Mask[1:0] =  2'b00   -> Counter[127:0] = {Nonce[31:0],       IV0[63:0], 4'h00000001} (only 1 IV exp ected) regular CTR  *                                                                          2'b01   -> Counter[127:0] = {Nonce[31:0],       IV0[63:0], IV1[31:0]}   (2 IV expected ) CCMP  *                                                                          2'b10   -> Counter[127:0] = {IV1[63:0],         IV0[31:0], Nonce[31:0]} (2 IV expected ) GCM with SCI  *                                                                          2'b11   -> Counter[127:0] = {IDecode.SCI[63:0], IV0[31:0], Nonce[31:0]} (1 IV expected ) GCM w/o SCI  *                 Nonce_Hi            =              Nonce[31:24] 8 most significant bits of 32-bit long nonce  *                                                    Used by AES in counter mode  *                 CkSum_dst_address   =              35 MSB of pointer to cksum dst location (i.e., cache-line aligned)  *  X0             IV_Offset_Hi        =              On first frag:           5 MSB of 8-bit IV offset; will be concatenated to  *                                                                             the top of PacketDescriptor_t.srcLengthIVOffUseIVNext.IV_Offset  *                                                    On subsequent frags:     Ignored  */
end_comment

begin_comment
comment|/* #define PKT_DSC_LOADHMACKEY */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_LOADHMACKEY_OLD
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_LOADHMACKEY_LOAD
value|1
end_define

begin_define
define|#
directive|define
name|PKT_DSC_LOADHMACKEY_LSB
value|63
end_define

begin_define
define|#
directive|define
name|PKT_DSC_LOADHMACKEY_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|PKT_DSC_LOADHMACKEY_MASK
define|\
value|(PKT_DSC_LOADHMACKEY_BITS<< PKT_DSC_LOADHMACKEY_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_PADHASH */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_PADHASH_PADDED
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_PADHASH_PAD
value|1
end_define

begin_comment
comment|/* requires padding */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_PADHASH_LSB
value|62
end_define

begin_define
define|#
directive|define
name|PKT_DSC_PADHASH_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|PKT_DSC_PADHASH_MASK
value|(PKT_DSC_PADHASH_BITS<< PKT_DSC_PADHASH_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_HASHBYTES */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_HASHBYTES_ALL8
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_HASHBYTES_MSB
value|1
end_define

begin_define
define|#
directive|define
name|PKT_DSC_HASHBYTES_MSW
value|2
end_define

begin_define
define|#
directive|define
name|PKT_DSC_HASHBYTES_LSB
value|59
end_define

begin_define
define|#
directive|define
name|PKT_DSC_HASHBYTES_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_HASHBYTES_MASK
define|\
value|(PKT_DSC_HASHBYTES_BITS<< PKT_DSC_HASHBYTES_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_NEXT */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_NEXT_FINISH
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_NEXT_DO
value|1
end_define

begin_define
define|#
directive|define
name|PKT_DSC_NEXT_LSB
value|58
end_define

begin_define
define|#
directive|define
name|PKT_DSC_NEXT_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|PKT_DSC_NEXT_MASK
value|(PKT_DSC_NEXT_BITS<< PKT_DSC_NEXT_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_IV */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_IV_OLD
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_IV_NEW
value|1
end_define

begin_define
define|#
directive|define
name|PKT_DSC_IV_LSB
value|57
end_define

begin_define
define|#
directive|define
name|PKT_DSC_IV_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|PKT_DSC_IV_MASK
value|(PKT_DSC_IV_BITS<< PKT_DSC_IV_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_IVOFF */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_IVOFF_LSB
value|54
end_define

begin_define
define|#
directive|define
name|PKT_DSC_IVOFF_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_IVOFF_MASK
value|(PKT_DSC_IVOFF_BITS<< PKT_DSC_IVOFF_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_PKTLEN */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_PKTLEN_LSB
value|43
end_define

begin_define
define|#
directive|define
name|PKT_DSC_PKTLEN_BITS
value|ELEVEN_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_PKTLEN_MASK
value|(PKT_DSC_PKTLEN_BITS<< PKT_DSC_PKTLEN_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_NLHMAC */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_NLHMAC_LSB
value|42
end_define

begin_define
define|#
directive|define
name|PKT_DSC_NLHMAC_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|PKT_DSC_NLHMAC_MASK
value|(PKT_DSC_NLHMAC_BITS<< PKT_DSC_NLHMAC_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_BREAK */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_BREAK_OLD
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_BREAK_NEW
value|1
end_define

begin_define
define|#
directive|define
name|PKT_DSC_BREAK_LSB
value|41
end_define

begin_define
define|#
directive|define
name|PKT_DSC_BREAK_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|PKT_DSC_BREAK_MASK
value|(PKT_DSC_BREAK_BITS<< PKT_DSC_BREAK_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_WAIT */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_WAIT_OLD
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_WAIT_NEW
value|1
end_define

begin_define
define|#
directive|define
name|PKT_DSC_WAIT_LSB
value|40
end_define

begin_define
define|#
directive|define
name|PKT_DSC_WAIT_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|PKT_DSC_WAIT_MASK
value|(PKT_DSC_WAIT_BITS<< PKT_DSC_WAIT_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_SEGADDR */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_SEGADDR_LSB
value|5
end_define

begin_define
define|#
directive|define
name|PKT_DSC_SEGADDR_BITS
value|FOURTY_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_SEGADDR_MASK
define|\
value|(PKT_DSC_SEGADDR_BITS<< PKT_DSC_SEGADDR_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_SRTCP */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_SRTCP_OFF
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_SRTCP_ON
value|1
end_define

begin_define
define|#
directive|define
name|PKT_DSC_SRTCP_LSB
value|4
end_define

begin_define
define|#
directive|define
name|PKT_DSC_SRTCP_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|PKT_DSC_SRTCP_MASK
value|(PKT_DSC_SRTCP_BITS<< PKT_DSC_SRTCP_LSB)
end_define

begin_define
define|#
directive|define
name|PKT_DSC_SEGOFFSET_LSB
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_SEGOFFSET_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_SEGOFFSET_MASK
define|\
value|(PKT_DSC_SEGOFFSET_BITS<< PKT_DSC_SEGOFFSET_LSB)
end_define

begin_comment
comment|/* **********************************************************************  *       PacketDescriptor_t.dstDataSettings  * **********************************************************************  */
end_comment

begin_comment
comment|/* #define PKT_DSC_ARC4BYTECOUNT */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_ARC4BYTECOUNT_ALL8
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_ARC4BYTECOUNT_MSB
value|1
end_define

begin_define
define|#
directive|define
name|PKT_DSC_ARC4BYTECOUNT_MSW
value|2
end_define

begin_define
define|#
directive|define
name|PKT_DSC_ARC4BYTECOUNT_LSB
value|60
end_define

begin_define
define|#
directive|define
name|PKT_DSC_ARC4BYTECOUNT_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_ARC4BYTECOUNT_MASK
value|(PKT_DSC_ARC4BYTECOUNT_BITS<< PKT_DSC_ARC4BYTECOUNT_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_SYM_OP (symmetric key operation) */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_SYM_OP_DECRYPT
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_SYM_OP_ENCRYPT
value|1
end_define

begin_define
define|#
directive|define
name|PKT_DSC_SYM_OP_LSB
value|59
end_define

begin_define
define|#
directive|define
name|PKT_DSC_SYM_OP_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|PKT_DSC_SYM_OP_MASK
value|(PKT_DSC_SYM_OP_BITS<< PKT_DSC_SYM_OP_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_CPHROFF */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_CPHROFF_LSB
value|56
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CPHROFF_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CPHROFF_MASK
value|(PKT_DSC_CPHROFF_BITS<< PKT_DSC_CPHROFF_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_HASHOFF */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_HASHOFF_LSB
value|54
end_define

begin_define
define|#
directive|define
name|PKT_DSC_HASHOFF_BITS
value|TWO_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_HASHOFF_MASK
value|(PKT_DSC_HASHOFF_BITS<< PKT_DSC_HASHOFF_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_HASHSRC */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_HASHSRC_DMA
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_HASHSRC_CIPHER
value|1
end_define

begin_define
define|#
directive|define
name|PKT_DSC_HASHSRC_LSB
value|53
end_define

begin_define
define|#
directive|define
name|PKT_DSC_HASHSRC_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|PKT_DSC_HASHSRC_MASK
value|(PKT_DSC_HASHSRC_BITS<< PKT_DSC_HASHSRC_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_CKSUMOFF */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_CKSUMOFF_LSB
value|41
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CKSUMOFF_BITS
value|TWELVE_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CKSUMOFF_MASK
value|(PKT_DSC_CKSUMOFF_BITS<< PKT_DSC_CKSUMOFF_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_CKSUMSRC */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_CKSUMSRC_DMA
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CKSUMSRC_CIPHER
value|1
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CKSUMSRC_LSB
value|40
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CKSUMSRC_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CKSUMSRC_MASK
value|(PKT_DSC_CKSUMSRC_BITS<< PKT_DSC_CKSUMSRC_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_CPHR_DST_ADDR */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_CPHR_DST_ADDR_LSB
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CPHR_DST_ADDR_BITS
value|FOURTY_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CPHR_DST_ADDR_MASK
define|\
value|(PKT_DSC_CPHR_DST_ADDR_BITS<< PKT_DSC_CPHR_DST_ADDR_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_CPHR_DST_DWOFFSET */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_CPHR_DST_DWOFFSET_LSB
value|3
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CPHR_DST_DWOFFSET_BITS
value|TWO_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CPHR_DST_DWOFFSET_MASK
define|\
value|(PKT_DSC_CPHR_DST_DWOFFSET_BITS<< PKT_DSC_CPHR_DST_DWOFFSET_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_CPHR_DST_OFFSET */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_CPHR_DST_OFFSET_LSB
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CPHR_DST_OFFSET_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CPHR_DST_OFFSET_MASK
define|\
value|(PKT_DSC_CPHR_DST_OFFSET_BITS<< PKT_DSC_CPHR_DST_OFFSET_LSB)
end_define

begin_comment
comment|/* **********************************************************************  *       PacketDescriptor_t.authDstNonceLow  * **********************************************************************  */
end_comment

begin_comment
comment|/* #define PKT_DSC_NONCE_LOW */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_NONCE_LOW_LSB
value|40
end_define

begin_define
define|#
directive|define
name|PKT_DSC_NONCE_LOW_BITS
value|TWENTYFOUR_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_NONCE_LOW_MASK
define|\
value|(PKT_DSC_NONCE_LOW_BITS<< PKT_DSC_NONCE_LOW_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_AUTH_DST_ADDR */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_AUTH_DST_ADDR_LSB
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_AUTH_DST_ADDR_BITS
value|FOURTY_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_AUTH_DST_ADDR_MASK
define|\
value|(PKT_DSC_AUTH_DST_ADDR_BITS<< PKT_DSC_AUTH_DST_ADDR_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_CIPH_OFF_HI */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_CIPH_OFF_HI_LSB
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CIPH_OFF_HI_BITS
value|FIVE_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CIPH_OFF_HI_MASK
value|(PKT_DSC_CIPH_OFF_HI_BITS<< PKT_DSC_CIPH_OFF_HI_LSB)
end_define

begin_comment
comment|/* **********************************************************************  *       PacketDescriptor_t.ckSumDstNonceHiCFBMaskLLWMask  * **********************************************************************  */
end_comment

begin_comment
comment|/* #define PKT_DSC_HASH_BYTE_OFF */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_HASH_BYTE_OFF_LSB
value|61
end_define

begin_define
define|#
directive|define
name|PKT_DSC_HASH_BYTE_OFF_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_HASH_BYTE_OFF_MASK
value|(PKT_DSC_HASH_BYTE_OFF_BITS<< PKT_DSC_HASH_BYTE_OFF_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_PKTLEN_BYTES */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_PKTLEN_BYTES_LSB
value|58
end_define

begin_define
define|#
directive|define
name|PKT_DSC_PKTLEN_BYTES_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_PKTLEN_BYTES_MASK
value|(PKT_DSC_PKTLEN_BYTES_BITS<< PKT_DSC_PKTLEN_BYTES_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_LASTWORD */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_LASTWORD_128
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_LASTWORD_96MASK
value|1
end_define

begin_define
define|#
directive|define
name|PKT_DSC_LASTWORD_64MASK
value|2
end_define

begin_define
define|#
directive|define
name|PKT_DSC_LASTWORD_32MASK
value|3
end_define

begin_define
define|#
directive|define
name|PKT_DSC_LASTWORD_LSB
value|56
end_define

begin_define
define|#
directive|define
name|PKT_DSC_LASTWORD_BITS
value|TWO_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_LASTWORD_MASK
value|(PKT_DSC_LASTWORD_BITS<< PKT_DSC_LASTWORD_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_CFB_MASK */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_CFB_MASK_LSB
value|48
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CFB_MASK_BITS
value|EIGHT_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CFB_MASK_MASK
value|(PKT_DSC_CFB_MASK_BITS<< PKT_DSC_CFB_MASK_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_NONCE_HI */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_NONCE_HI_LSB
value|40
end_define

begin_define
define|#
directive|define
name|PKT_DSC_NONCE_HI_BITS
value|EIGHT_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_NONCE_HI_MASK
value|(PKT_DSC_NONCE_HI_BITS<< PKT_DSC_NONCE_HI_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_CKSUM_DST_ADDR */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_CKSUM_DST_ADDR_LSB
value|5
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CKSUM_DST_ADDR_BITS
value|THIRTY_FIVE_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_CKSUM_DST_ADDR_MASK
value|(PKT_DSC_CKSUM_DST_ADDR_BITS<< PKT_DSC_CKSUM_DST_ADDR_LSB)
end_define

begin_comment
comment|/* #define PKT_DSC_IV_OFF_HI */
end_comment

begin_define
define|#
directive|define
name|PKT_DSC_IV_OFF_HI_LSB
value|0
end_define

begin_define
define|#
directive|define
name|PKT_DSC_IV_OFF_HI_BITS
value|FIVE_BITS
end_define

begin_define
define|#
directive|define
name|PKT_DSC_IV_OFF_HI_MASK
value|(PKT_DSC_IV_OFF_HI_BITS<< PKT_DSC_IV_OFF_HI_LSB)
end_define

begin_comment
comment|/* ******************************************************************  *             Control Error Code and Conditions  * ******************************************************************  */
end_comment

begin_define
define|#
directive|define
name|CTL_ERR_NONE
value|0x0000
end_define

begin_comment
comment|/* No Error */
end_comment

begin_define
define|#
directive|define
name|CTL_ERR_CIPHER_OP
value|0x0001
end_define

begin_comment
comment|/* Unknown Cipher Op */
end_comment

begin_define
define|#
directive|define
name|CTL_ERR_MODE
value|0x0002
end_define

begin_comment
comment|/* Unknown or Not Allowed Mode */
end_comment

begin_define
define|#
directive|define
name|CTL_ERR_CHKSUM_SRC
value|0x0004
end_define

begin_comment
comment|/* Unknown CkSum Src - UNUSED */
end_comment

begin_define
define|#
directive|define
name|CTL_ERR_CFB_MASK
value|0x0008
end_define

begin_comment
comment|/* Forbidden CFB Mask - UNUSED */
end_comment

begin_define
define|#
directive|define
name|CTL_ERR_OP
value|0x0010
end_define

begin_comment
comment|/* Unknown Ctrl Op - UNUSED */
end_comment

begin_define
define|#
directive|define
name|CTL_ERR_UNDEF1
value|0x0020
end_define

begin_comment
comment|/* UNUSED */
end_comment

begin_define
define|#
directive|define
name|CTL_ERR_UNDEF2
value|0x0040
end_define

begin_comment
comment|/* UNUSED */
end_comment

begin_define
define|#
directive|define
name|CTL_ERR_DATA_READ
value|0x0080
end_define

begin_comment
comment|/* Data Read Error */
end_comment

begin_define
define|#
directive|define
name|CTL_ERR_DESC_CTRL
value|0x0100
end_define

begin_comment
comment|/* Descriptor Ctrl Field Error */
end_comment

begin_define
define|#
directive|define
name|CTL_ERR_TIMEOUT
value|0x1000
end_define

begin_comment
comment|/* Message Response Timeout */
end_comment

begin_comment
comment|/* ******************************************************************  *             Data Error Code and Conditions  * ******************************************************************  */
end_comment

begin_define
define|#
directive|define
name|DATA_ERR_NONE
value|0x0000
end_define

begin_comment
comment|/* No Error */
end_comment

begin_define
define|#
directive|define
name|DATA_ERR_LEN_CIPHER
value|0x0001
end_define

begin_comment
comment|/* Not Enough Data To Cipher */
end_comment

begin_define
define|#
directive|define
name|DATA_ERR_IV_ADDR
value|0x0002
end_define

begin_comment
comment|/* Illegal IV Loacation */
end_comment

begin_define
define|#
directive|define
name|DATA_ERR_WD_LEN_AES
value|0x0004
end_define

begin_comment
comment|/* Illegal Nb Words To AES */
end_comment

begin_define
define|#
directive|define
name|DATA_ERR_BYTE_COUNT
value|0x0008
end_define

begin_comment
comment|/* Illegal Pad And ByteCount Spec */
end_comment

begin_define
define|#
directive|define
name|DATA_ERR_LEN_CKSUM
value|0x0010
end_define

begin_comment
comment|/* Not Enough Data To CkSum */
end_comment

begin_define
define|#
directive|define
name|DATA_ERR_OP
value|0x0020
end_define

begin_comment
comment|/* Unknown Data Op */
end_comment

begin_define
define|#
directive|define
name|DATA_ERR_UNDEF1
value|0x0040
end_define

begin_comment
comment|/* UNUSED */
end_comment

begin_define
define|#
directive|define
name|DATA_ERR_READ
value|0x0080
end_define

begin_comment
comment|/* Data Read Error */
end_comment

begin_define
define|#
directive|define
name|DATA_ERR_WRITE
value|0x0100
end_define

begin_comment
comment|/* Data Write Error */
end_comment

begin_comment
comment|/*  * Common Descriptor   * NOTE:  Size of struct is size of cacheline.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|OperationDescriptor_s
block|{
name|uint64_t
name|phys_self
decl_stmt|;
name|uint32_t
name|stn_id
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|cpu
decl_stmt|;
name|uint32_t
name|seq_num
decl_stmt|;
name|uint64_t
name|reserved
decl_stmt|;
block|}
name|OperationDescriptor_t
operator|,
typedef|*
name|OperationDescriptor_pt
typedef|;
end_typedef

begin_comment
comment|/*  * This defines the security data descriptor format  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|PacketDescriptor_s
block|{
name|uint64_t
name|srcLengthIVOffUseIVNext
decl_stmt|;
name|uint64_t
name|dstDataSettings
decl_stmt|;
name|uint64_t
name|authDstNonceLow
decl_stmt|;
name|uint64_t
name|ckSumDstNonceHiCFBMaskLLWMask
decl_stmt|;
block|}
name|PacketDescriptor_t
operator|,
typedef|*
name|PacketDescriptor_pt
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
modifier|*
name|user_auth
decl_stmt|;
name|uint8_t
modifier|*
name|user_src
decl_stmt|;
name|uint8_t
modifier|*
name|user_dest
decl_stmt|;
name|uint8_t
modifier|*
name|user_state
decl_stmt|;
name|uint8_t
modifier|*
name|kern_auth
decl_stmt|;
name|uint8_t
modifier|*
name|kern_src
decl_stmt|;
name|uint8_t
modifier|*
name|kern_dest
decl_stmt|;
name|uint8_t
modifier|*
name|kern_state
decl_stmt|;
name|uint8_t
modifier|*
name|aligned_auth
decl_stmt|;
name|uint8_t
modifier|*
name|aligned_src
decl_stmt|;
name|uint8_t
modifier|*
name|aligned_dest
decl_stmt|;
name|uint8_t
modifier|*
name|aligned_state
decl_stmt|;
block|}
name|xlr_sec_drv_user_t
operator|,
typedef|*
name|xlr_sec_drv_user_pt
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|symkey_desc
block|{
name|OperationDescriptor_t
name|op_ctl
decl_stmt|;
comment|/* size is cacheline */
name|PacketDescriptor_t
name|pkt_desc
index|[
literal|2
index|]
decl_stmt|;
comment|/* size is cacheline  */
name|ControlDescriptor_t
name|ctl_desc
decl_stmt|;
comment|/*  makes this aligned */
name|uint64_t
name|control
decl_stmt|;
comment|/* message word0 */
name|uint64_t
name|data
decl_stmt|;
comment|/* message word1 */
name|uint64_t
name|ctl_result
decl_stmt|;
name|uint64_t
name|data_result
decl_stmt|;
name|struct
name|symkey_desc
modifier|*
name|alloc
decl_stmt|;
comment|/* real allocated addr */
name|xlr_sec_drv_user_t
name|user
decl_stmt|;
comment|//    volatile atomic_t       flag_complete;
comment|//    struct semaphore        sem_complete;
comment|//    wait_queue_t            submit_wait;
name|uint8_t
modifier|*
name|next_src_buf
decl_stmt|;
name|uint32_t
name|next_src_len
decl_stmt|;
name|uint8_t
modifier|*
name|next_dest_buf
decl_stmt|;
name|uint32_t
name|next_dest_len
decl_stmt|;
name|uint8_t
modifier|*
name|next_auth_dest
decl_stmt|;
name|uint8_t
modifier|*
name|next_cksum_dest
decl_stmt|;
name|void
modifier|*
name|ses
decl_stmt|;
block|}
name|symkey_desc_t
operator|,
typedef|*
name|symkey_desc_pt
typedef|;
end_typedef

begin_comment
comment|/*  * **************************************************************************  *                                 RSA Block  * **************************************************************************  */
end_comment

begin_comment
comment|/*  *                                 RSA and ECC Block  *                                 =================  *  * A 2-word message ring descriptor is used to pass all information  * pertaining to the RSA or ECC operation:  *  *  63  61 60         54     53     52      40 39          5 4                 3 2                      0  *  -----------------------------------------------------------------------------------------------------  * | Ctrl |  Op Class   | Valid Op | Op Ctrl0 | Source Addr | Software Scratch0 | Global src data offset |  *  -----------------------------------------------------------------------------------------------------  *    3         7           1           13         35                 2                     3  *  *  *  63  61 60            54     53         52             51     50      40 39        5 4                 3 2                      0  *  --------------------------------------------------------------------------------------------------------------------------------  * | Ctrl | Destination Id | WRB_COH | WRB_L2ALLOC | DF_L2ALLOC | Op Ctrl1 | Dest Addr | Software Scratch1 | Global dst data offset |  *  --------------------------------------------------------------------------------------------------------------------------------  *    3            7            1          1              1          11         35                2                     3  *  *  *             Op Class                =        7'h0_0     Modular exponentiation  *                                              7'h0_1     ECC (including prime modular ops and binary GF ops)  *                                              REMAINDER  UNDEF  *                                                 *             Valid Op                =        1'b1       Will cause operation to start; descriptors sent back at end of operation  *                                              1'b0       No operation performed; descriptors sent back right away  *  *                                                                   RSA                 ECC  *                                                                   ===                 ===  *             Op Ctrl0                =                             BlockWidth[1]	 {TYPE[6:0], FUNCTION[5:0]}  *                                                                   LoadConstant[1]  *                                                                   ExponentWidth[10:0]  *                                               RSA Only  *                                               ========  *                                               Block Width             =        1'b1       1024 bit op  *                                                                       =        1'b0       512  bit op  *                                               Load Constant           =        1'b1       Load constant from data structure  *                                                                                1'b0       Preserve old constant (this assumes   *                                                                                           Source Addr points to RSAData_pt->Exponent  *                                                                                           or that the length of Constant is 0)  *                                               Exponent Width          =                   11-bit expression of exponent width EXPRESSED IN NUMBER OF BITS  *  *                                               ECC Only  *                                               ========  *  *                                               TYPE      = 7'h0_0 ECC prime 160  *                                                           7'h0_1 ECC prime 192  *                                                           7'h0_2 ECC prime 224  *                                                           7'h0_3 ECC prime 256  *                                                           7'h0_4 ECC prime 384  *                                                           7'h0_5 ECC prime 512  *  *                                                           7'h0_6 through 7'h1_f  UNDEF  *  *                                                           7'h2_0 ECC bin   163  *                                                           7'h2_1 ECC bin   191  *                                                           7'h2_2 ECC bin   233  *  *                                                           7'h2_3 through 7'h6_f  UNDEF  *  *                                                           7'h7_0 ECC UC load  *  *                                                           7'b7_1 through 7'b7_f  UNDEF  *  *                                                                   Prime field                                    Binary field  *                                                                   ===========                                    ============  *                                               FUNCTION  = 6'h0_0  Point multiplication     R = k.P               Point multiplication       R = k.P  *                                                           6'h0_1  Point addition           R = P + Q             Binary GF inversion        C(x) = 1 / A(x) mod F(x)  *                                                           6'h0_2  Point double             R = 2 x P             Binary GF multiplication   C(x) = B(x) * A(x) mod F(x)  *                                                           6'h0_3  Point verification       R ?                   Binary GF addition         C(x) = B(x) + A(x) mod F(x)  *                                                           6'h0_4  Modular addition         c = x + y mod m	    UNDEF  *                                                           6'h0_5  Modular substraction     c = x - y mod m	    UNDEF  *                                                           6'h0_6  Modular multiplication   c = x * y mod m       UNDEF  *                                                           6'h0_7  Modular division         c = x / y mod m       UNDEF  *                                                           6'h0_8  Modular inversion        c = 1 / y mod m       UNDEF  *                                                           6'h0_9  Modular reduction        c = x mod m           UNDEF  *  *                                                           6'h0_a  *                                                           through UNDEF                                          UNDEF  *                                                           6'h3_f  *  *             Source Addr             =                   35 MSB of pointer to source address (i.e., cache-line aligned)  *  *             Software Scratch0       =                   Two bit field ignored by engine and returned as is in free descriptor  *  *             Global src data offset  =                   Nb BYTES to right-shift data by before presenting it to engines  *                                                         (0-7); allows realignment of byte-aligned, non-double-word aligned data  *  *                                                                   RSA                 ECC  *                                                                   ===                 ===  *             OpCtrl1                 =                             ModulusWidth[10:0]  Not used  *                                               RSA Only  *                                               ========  *                                               Modulus Width           =                   11-bit expression of modulus width EXPRESSED IN NUMBER OF BITS  *  *             Dest Addr               =                   35 MSB of pointer to destination address (i.e., cache-line aligned)  *  *             Software Scratch1       =                   Two bit field ignored by engine and returned as is in free descriptor  *  *             Global dst data offset  =                   Nb BYTES to left-shift (double-word boundary aligned) data by before writing it to memory  *                                                   *  */
end_comment

begin_comment
comment|/*   * ECC data formats  */
end_comment

begin_comment
comment|/**********************************************************  *                                                        *  *     ECC prime data formats                             *  *                                                        *  **********************************************************  *  *  *  The size of all quantities below is that of the precision  *  of the chosen op (160, 192, ...) ROUNDED UP to a multiple  *  of 8 bytes, i.e., 3 dwords (160, 192), 4 dwords (224, 256)  *  6 dwords (384) and 8 dwords (512) and padded with zeroes  *  when necessary.  *  *  The only exception to this is the key quantity (k) which  *  needs to be rounded up to 32 bytes in all cases and padded  *  with zeroes; therefore the key needs to be 4 dwords (160, 192,  *  224, 256) or 8 dwords (384, 512)  *  *  The total lengths in dwords that are read and in  *  bytes that are written, for each operation and   *  length group, are specified at the bottom of each   *  datastructure.  *  *  In all that follows, m is the modulus and cst is the constant,  *  cst = 2 ^ (2*length + 4) mod m . a and b are the curve  *  parameters.  *  *  0) UC load  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   Dword_0                 N/A  *                 .  *                 .  *                 .  *                 Dword_331  *                 332 dw  *  *  1) Point multiplication       R(x_r, y_r) = k . P(x_p, y_p)  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   x_p      dst+glb_off->  x_r  *                 x_p                     y_r  *                 y_p			   2x(3/4/6/8)=  *                 y_p			   6/8/12/16 dw  *                 a  *                 k			     *                 m  *                 cst  *                 7x(3/4/6/8)+(4/4/8/8)=  *                 25/32/50/64 dw  *  *  2) Point addition             R(x_r, y_r) = P(x_p, y_p) + Q(x_q, y_q)  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   x_p      dst+glb_off->  x_r  *                 y_p                     y_r  *                 x_q			   2x(3/4/6/8)=  *                 y_q			   6/8/12/16 dw  *                 a  *                 m  *                 cst  *                 7x(3/4/6/8)=  *                 21/28/42/56 dw  *  *  3) Point double               R(x_r, y_r) = 2 . P(x_p, y_p)  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   x_p      dst+glb_off->  x_r  *                 y_p                     y_r  *                 a			   2x(3/4/6/8)=  *                 m			   6/8/12/16 dw  *                 cst  *                 5x(3/4/6/8)=  *                 15/20/30/40 dw  *  *  4) Point verification         Is_On_Curve = P(x_p, y_p) on curve ? 1 : 0  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   x_p      dst+glb_off->  Is_On_Curve  *                 y_p			   1 dw  *                 a  *                 b  *                 m  *                 cst  *                 6x(3/4/6/8)=  *                 18/24/36/48 dw  *  *  5) Modular addition           c = x + y mod m  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   x        dst+glb_off->  c  *                 y			   3/4/6/8 dw  *                 m  *                 3x(3/4/6/8)=  *                 9/12/18/24 dw  *  *  6) Modular substraction       c = x - y mod m  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   x        dst+glb_off->  c  *                 y			   3/4/6/8 dw  *                 m  *                 3x(3/4/6/8)=  *                 9/12/18/24 dw  *  *  7) Modular multiplication     c = x * y mod m  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   x        dst+glb_off->  c  *                 y			   3/4/6/8 dw  *                 m  *                 cst  *                 4x(3/4/6/8)=  *                 12/16/24/32 dw  *  *  8) Modular division           c = x / y mod m  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   y        dst+glb_off->  c  *                 x			   3/4/6/8 dw  *                 m  *                 3x(3/4/6/8)=  *                 9/12/18/24 dw  *  *  9) Modular inversion          c = 1 / y mod m  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   y        dst+glb_off->  c  *                 m			   3/4/6/8 dw  *                 2x(3/4/6/8)=  *                 6/8/12/16 dw  *  *  10) Modular reduction         c = x mod m  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   x        dst+glb_off->  c  *                 m			   3/4/6/8 dw  *                 2x(3/4/6/8)=  *                 6/8/12/16 dw  *  */
end_comment

begin_comment
comment|/**********************************************************  *                                                        *  *     ECC binary data formats                            *  *                                                        *  **********************************************************  *  *  *  The size of all quantities below is that of the precision  *  of the chosen op (163, 191, 233) ROUNDED UP to a multiple  *  of 8 bytes, i.e. 3 dwords for (163, 191) and 4 dwords for  *  (233), padded with zeroes as necessary.  *  *  The total lengths in dwords that are read and written,  *  for each operation and length group, are specified  *  at the bottom of each datastructure.  *  In all that follows, b is the curve parameter.  *  *  1) Point multiplication       R(x_r, y_r) = k . P(x_p, y_p)  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   b        dst+glb_off->  x_r  *                 k                       y_r  *                 x_p    		   2x(3/4)  *                 y_p			   6/8 dw  *                 4x(3/4)=  *                 12/16 dw  *  *  2) Binary GF inversion        C(x) = 1 / A(x) mod F(x)  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   A        dst+glb_off->  C  *		   1x(3/4)=                1x(3/4)  *                 3/4 dw		   3/4 dw  *  *  3) Binary GF multiplication   C(x) = B(x) * A(x) mod F(x)  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   A        dst+glb_off->  C  *                 B                       1x(3/4)  *		   2x(3/4)=		   3/4 dw  *                 6/8 dw  *  *  4) Binary GF addition         C(x) = B(x) + A(x) mod F(x)  *  *                 DATA IN                 DATA OUT  *                 =======                 ========  * src+glb_off->   A        dst+glb_off->  C  *                 B                       1x(3/4)  *		   2x(3/4)=		   3/4 dw  *                 6/8dw  *  */
end_comment

begin_comment
comment|/*  * RSA data format  */
end_comment

begin_comment
comment|/*  * IMPORTANT NOTE:   *  * As specified in the datastructures below,  * the engine assumes all data (including  * exponent and modulus) to be adjacent on  * dword boundaries, e.g.,  *  * Operation length = 512 bits  * Exponent  length = 16  bits  * Modulus   length = 512 bits  *  * The engine expects to read:  *  *   63                    0  *   -----------------------  *  |                       | Constant0  *   -----------------------  *  |                       | Constant1  *   -----------------------  *  |                       | Constant2  *   -----------------------  *  |                       | Constant3  *   -----------------------  *  |                       | Constant4  *   -----------------------  *  |                       | Constant5  *   -----------------------  *  |                       | Constant6  *   -----------------------  *  |                       | Constant7  *   -----------------------  *  |      IGNORED    |B1|B0| Exponent0    (Exponent length = 16 bits = 2 bytes, so only 2 least significant bytes of exponent used)  *   -----------------------  *  |                       | Modulus0  *   -----------------------  *  |                       | Modulus1  *   -----------------------  *  |                       | Modulus2  *   -----------------------  *  |                       | Modulus3  *   -----------------------  *  |                       | Modulus4  *   -----------------------  *  |                       | Modulus5  *   -----------------------  *  |                       | Modulus6  *   -----------------------  *  |                       | Modulus7  *   -----------------------  *  |                       | Message0  *   -----------------------  *  |                       | Message1  *   -----------------------  *  |                       | Message2  *   -----------------------  *  |                       | Message3  *   -----------------------  *  |                       | Message4  *   -----------------------  *  |                       | Message5  *   -----------------------  *  |                       | Message6  *   -----------------------  *  |                       | Message7  *   -----------------------  *  */
end_comment

begin_comment
comment|/* #define PUBKEY_CTL_CTL */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_CTL_CTL_LSB
value|61
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_CTL_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_CTL_MASK
value|(PUBKEY_CTL_CTL_BITS<< PUBKEY_CTL_CTL_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_CTL_OP_CLASS */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_CTL_OP_CLASS_RSA
value|0
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_OP_CLASS_ECC
value|1
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_OP_CLASS_LSB
value|54
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_OP_CLASS_BITS
value|SEVEN_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_OP_CLASS_MASK
value|(PUBKEY_CTL_OP_CLASS_BITS<< PUBKEY_CTL_OP_CLASS_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_CTL_VALID */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_CTL_VALID_FALSE
value|0
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_VALID_TRUE
value|1
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_VALID_LSB
value|53
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_VALID_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_VALID_MASK
define|\
value|(PUBKEY_CTL_VALID_BITS<< PUBKEY_CTL_VALID_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_CTL_ECC_TYPE */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_TYPE_PRIME_160
value|0
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_TYPE_PRIME_192
value|1
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_TYPE_PRIME_224
value|2
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_TYPE_PRIME_256
value|3
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_TYPE_PRIME_384
value|4
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_TYPE_PRIME_512
value|5
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_TYPE_BIN_163
value|0x20
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_TYPE_BIN_191
value|0x21
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_TYPE_BIN_233
value|0x22
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_TYPE_UC_LOAD
value|0x70
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_TYPE_LSB
value|46
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_TYPE_BITS
value|SEVEN_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_TYPE_MASK
value|(PUBKEY_CTL_ECC_TYPE_BITS<< PUBKEY_CTL_ECC_TYPE_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_CTL_ECC_FUNCTION */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_FUNCTION_NOP
value|0
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_FUNCTION_POINT_MUL
value|0
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_FUNCTION_POINT_ADD
value|1
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_FUNCTION_POINT_DBL
value|2
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_FUNCTION_POINT_VFY
value|3
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_FUNCTION_MODULAR_ADD
value|4
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_FUNCTION_MODULAR_SUB
value|5
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_FUNCTION_MODULAR_MUL
value|6
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_FUNCTION_MODULAR_DIV
value|7
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_FUNCTION_MODULAR_INV
value|8
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_FUNCTION_MODULAR_RED
value|9
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_FUNCTION_LSB
value|40
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_FUNCTION_BITS
value|SIX_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_ECC_FUNCTION_MASK
value|(PUBKEY_CTL_ECC_FUNCTION_BITS<< PUBKEY_CTL_ECC_FUNCTION_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_CTL_BLKWIDTH */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_CTL_BLKWIDTH_512
value|0
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_BLKWIDTH_1024
value|1
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_BLKWIDTH_LSB
value|52
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_BLKWIDTH_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_BLKWIDTH_MASK
define|\
value|(PUBKEY_CTL_BLKWIDTH_BITS<< PUBKEY_CTL_BLKWIDTH_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_CTL_LD_CONST */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_CTL_LD_CONST_OLD
value|0
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_LD_CONST_NEW
value|1
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_LD_CONST_LSB
value|51
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_LD_CONST_BITS
value|ONE_BIT
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_LD_CONST_MASK
define|\
value|(PUBKEY_CTL_LD_CONST_BITS<< PUBKEY_CTL_LD_CONST_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_CTL_EXPWIDTH */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_CTL_EXPWIDTH_LSB
value|40
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_EXPWIDTH_BITS
value|ELEVEN_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_EXPWIDTH_MASK
define|\
value|(PUBKEY_CTL_EXPWIDTH_BITS<< PUBKEY_CTL_EXPWIDTH_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_CTL_SRCADDR */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_CTL_SRCADDR_LSB
value|0
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_SRCADDR_BITS
value|FOURTY_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_SRCADDR_MASK
define|\
value|(PUBKEY_CTL_SRCADDR_BITS<< PUBKEY_CTL_SRCADDR_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_CTL_SRC_OFFSET */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_CTL_SRC_OFFSET_LSB
value|0
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_SRC_OFFSET_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL_SRC_OFFSET_MASK
define|\
value|(PUBKEY_CTL_SRC_OFFSET_BITS<< PUBKEY_CTL_SRC_OFFSET_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_CTL1_CTL */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_CTL1_CTL_LSB
value|61
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL1_CTL_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL1_CTL_MASK
value|(PUBKEY_CTL_CTL_BITS<< PUBKEY_CTL_CTL_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_CTL1_MODWIDTH */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_CTL1_MODWIDTH_LSB
value|40
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL1_MODWIDTH_BITS
value|ELEVEN_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL1_MODWIDTH_MASK
define|\
value|(PUBKEY_CTL1_MODWIDTH_BITS<< PUBKEY_CTL1_MODWIDTH_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_CTL1_DSTADDR */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_CTL1_DSTADDR_LSB
value|0
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL1_DSTADDR_BITS
value|FOURTY_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL1_DSTADDR_MASK
define|\
value|(PUBKEY_CTL1_DSTADDR_BITS<< PUBKEY_CTL1_DSTADDR_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_CTL1_DST_OFFSET */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_CTL1_DST_OFFSET_LSB
value|0
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL1_DST_OFFSET_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_CTL1_DST_OFFSET_MASK
define|\
value|(PUBKEY_CTL1_DST_OFFSET_BITS<< PUBKEY_CTL1_DST_OFFSET_LSB)
end_define

begin_comment
comment|/*  * Upon completion of operation, the RSA block returns a 2-word free descriptor  * in the following format:  *  *  63  61 60            54 53   52 51       49  48          40 39             5 4                 3 2                      0  *  -------------------------------------------------------------------------------------------------------------------------  * | Ctrl | Destination Id | 2'b00 | Desc Ctrl | Control Error | Source Address | Software Scratch0 | Global src data offset |  *  -------------------------------------------------------------------------------------------------------------------------  * | Ctrl | Destination Id | 2'b00 | Desc Ctrl |   Data Error  | Dest Address   | Software Scratch1 | Global dst data offset |  *  -------------------------------------------------------------------------------------------------------------------------  *  * The Control and Data Error codes are enumerated below  *  *                                Error conditions  *                                ================  *  *             Control Error Code                  Control Error Condition  *             ------------------                  -----------------------  *             9'h000                              No Error  *             9'h001                              Undefined Op Class  *             9'h002                              Undefined ECC TYPE       (ECC only)  *             9'h004                              Undefined ECC FUNCTION   (ECC only)  *             9'h008                              ECC timeout              (ECC only)  *             9'h010                              UNUSED  *             9'h020                              UNUSED  *             9'h040                              UNUSED  *             9'h080                              Data Read Error  *             9'h100                              Descriptor Ctrl Field Error        (D0.Ctrl != SOP || D1.Ctrl != EOP)  *  *             Data Error Code                     Data Error Condition  *             ---------------                     --------------------  *             9'h000                              No Error  *             9'h001                              Exponent Width> Block Width (RSA Only)  *             9'h002                              Modulus Width> Block Width (RSA Only)  *             9'h004                              UNUSED  *             9'h008                              UNUSED  *             9'h010                              UNUSED  *             9'h020                              UNUSED  *             9'h040                              UNUSED  *             9'h080                              Data Read Error  *             9'h100                              UNUSED  */
end_comment

begin_comment
comment|/*  * Result Data Word for Message Ring Descriptor  */
end_comment

begin_comment
comment|/* #define PUBKEY_RSLT_CTL_CTL */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_CTL_LSB
value|61
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_CTL_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_CTL_MASK
define|\
value|(PUBKEY_RSLT_CTL_CTL_BITS<< PUBKEY_RSLT_CTL_CTL_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_RSLT_CTL_DST_ID */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_DST_ID_LSB
value|54
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_DST_ID_BITS
value|SEVEN_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_DST_ID_MASK
define|\
value|(PUBKEY_RSLT_CTL_DST_ID_BITS<< PUBKEY_RSLT_CTL_DST_ID_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_RSLT_CTL_DESC_CTL */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_DESC_CTL_LSB
value|49
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_DESC_CTL_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_DESC_CTL_MASK
define|\
value|(PUBKEY_RSLT_CTL_DESC_CTL_BITS<< PUBKEY_RSLT_CTL_DESC_CTL_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_RSLT_CTL_ERROR */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_ERROR_LSB
value|40
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_ERROR_BITS
value|NINE_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_ERROR_MASK
define|\
value|(PUBKEY_RSLT_CTL_ERROR_BITS<< PUBKEY_RSLT_CTL_ERROR_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_RSLT_CTL_SRCADDR */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_SRCADDR_LSB
value|0
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_SRCADDR_BITS
value|FOURTY_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_CTL_SRCADDR_MASK
define|\
value|(PUBKEY_RSLT_CTL_SRCADDR_BITS<< PUBKEY_RSLT_CTL_SRCADDR_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_RSLT_DATA_CTL */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_CTL_LSB
value|61
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_CTL_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_CTL_MASK
define|\
value|(PUBKEY_RSLT_DATA_CTL_BITS<< PUBKEY_RSLT_DATA_CTL_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_RSLT_DATA_DST_ID */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_DST_ID_LSB
value|54
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_DST_ID_BITS
value|SEVEN_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_DST_ID_MASK
define|\
value|(PUBKEY_RSLT_DATA_DST_ID_BITS<< PUBKEY_RSLT_DATA_DST_ID_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_RSLT_DATA_DESC_CTL */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_DESC_CTL_LSB
value|49
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_DESC_CTL_BITS
value|THREE_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_DESC_CTL_MASK
define|\
value|(PUBKEY_RSLT_DATA_DESC_CTL_BITS<< PUBKEY_RSLT_DATA_DESC_CTL_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_RSLT_DATA_ERROR */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_ERROR_LSB
value|40
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_ERROR_BITS
value|NINE_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_ERROR_MASK
define|\
value|(PUBKEY_RSLT_DATA_ERROR_BITS<< PUBKEY_RSLT_DATA_ERROR_LSB)
end_define

begin_comment
comment|/* #define PUBKEY_RSLT_DATA_DSTADDR */
end_comment

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_DSTADDR_LSB
value|40
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_DSTADDR_BITS
value|FOURTY_BITS
end_define

begin_define
define|#
directive|define
name|PUBKEY_RSLT_DATA_DSTADDR_MASK
define|\
value|(PUBKEY_RSLT_DATA_DSTADDR_BITS<< PUBKEY_RSLT_DATA_DSTADDR_LSB)
end_define

begin_comment
comment|/*   * ******************************************************************  *             RSA Block - Data Error Code and Conditions  * ******************************************************************  */
end_comment

begin_define
define|#
directive|define
name|PK_CTL_ERR_NONE
value|0x0000
end_define

begin_comment
comment|/* No Error */
end_comment

begin_define
define|#
directive|define
name|PK_CTL_ERR_OP_CLASS
value|0x0001
end_define

begin_comment
comment|/* Undefined Op Class */
end_comment

begin_define
define|#
directive|define
name|PK_CTL_ERR_ECC_TYPE
value|0x0002
end_define

begin_comment
comment|/* Undefined ECC TYPE (ECC only) */
end_comment

begin_define
define|#
directive|define
name|PK_CTL_ERR_ECC_FUNCT
value|0x0004
end_define

begin_comment
comment|/* Undefined ECC FUNCTION   (ECC only) */
end_comment

begin_define
define|#
directive|define
name|PK_CTL_ERR_ECC_TIMEOUT
value|0x0008
end_define

begin_comment
comment|/* ECC timeout              (ECC only) */
end_comment

begin_define
define|#
directive|define
name|PK_CTL_ERR_READ
value|0x0080
end_define

begin_comment
comment|/* Data Read Error */
end_comment

begin_define
define|#
directive|define
name|PK_CTL_ERR_DESC
value|0x0100
end_define

begin_comment
comment|/* Descriptor Ctrl Field Error  (D0.Ctrl != SOP || D1.Ctrl != EOP) */
end_comment

begin_define
define|#
directive|define
name|PK_CTL_ERR_TIMEOUT
value|0x1000
end_define

begin_comment
comment|/* Message Responce Timeout */
end_comment

begin_define
define|#
directive|define
name|PK_DATA_ERR_NONE
value|0x0000
end_define

begin_comment
comment|/* No Error */
end_comment

begin_define
define|#
directive|define
name|PK_DATA_ERR_EXP_WIDTH
value|0x0001
end_define

begin_comment
comment|/* Exponent Width> Block Width */
end_comment

begin_define
define|#
directive|define
name|PK_DATA_ERR_MOD_WIDTH
value|0x0002
end_define

begin_comment
comment|/* Modulus Width> Block Width */
end_comment

begin_define
define|#
directive|define
name|PK_DATA_ERR_READ
value|0x0080
end_define

begin_comment
comment|/* Data Read Error */
end_comment

begin_comment
comment|/*  * This defines the RSA data format  */
end_comment

begin_comment
comment|/*  * typedef struct RSAData_s {  *  uint64_t            Constant;  *  uint64_t            Exponent;  *  uint64_t            Modulus;  * uint64_t            Message;  *} RSAData_t, *RSAData_pt;  *  * typedef RSAData_t DHData_t;  * typedef RSAData_pt DHData_pt;  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|UserPubData_s
block|{
name|uint8_t
modifier|*
name|source
decl_stmt|;
name|uint8_t
modifier|*
name|user_result
decl_stmt|;
name|uint32_t
name|result_length
decl_stmt|;
block|}
name|UserPubData_t
operator|,
typedef|*
name|UserPubData_pt
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pubkey_desc
block|{
name|OperationDescriptor_t
name|op_ctl
decl_stmt|;
comment|/* size is cacheline */
name|uint8_t
name|source
index|[
literal|1024
index|]
decl_stmt|;
name|uint8_t
name|dest
index|[
literal|256
index|]
decl_stmt|;
comment|/* 1024 makes cacheline-aligned */
name|uint64_t
name|control0
decl_stmt|;
name|uint64_t
name|control1
decl_stmt|;
name|uint64_t
name|ctl_result
decl_stmt|;
name|uint64_t
name|data_result
decl_stmt|;
name|struct
name|pubkey_desc
modifier|*
name|alloc
decl_stmt|;
name|UserPubData_t
name|kern
decl_stmt|;
comment|/* ptrs for temp buffers */
comment|//    volatile atomic_t       flag_complete;
comment|//    struct semaphore        sem_complete;
comment|//    wait_queue_t            submit_wait;
block|}
name|pubkey_desc_t
operator|,
typedef|*
name|pubkey_desc_pt
typedef|;
end_typedef

begin_comment
comment|/*  * KASUMI F8 and F9 use the IV0/IV1 fields :  *  *  63 41      40      39   37 36        32 31                                 0  *  ----------------------------------------------------------------------------  * |     |FX/DIRECTION|       | F8/BEARER  |              F8/COUNT              | IV0  *  ----------------------------------------------------------------------------   *              1                   5                         32  *  *  63                                   32 31                                 0  *  ----------------------------------------------------------------------------  * |                F9/FRESH               |              F9/COUNT              | IV1  *  ----------------------------------------------------------------------------  *                     32                                     32  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XLR_SEC_DESC_H_ */
end_comment

end_unit

