begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * b004.h  *  * Based on the Linux driver, by  * Christoph Niemann (niemann@swt.ruhr-uni-bochum.de)  *  * Ported to FreeBSD by Luigi Rizzo (luigi@iet.unipi.it)  * and Lorenzo Vicisano (l.vicisano@iet.unipi.it)  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christoph Niemann,  *      Luigi Rizzo and Lorenzo Vicisano - Dipartimento di Ingegneria  *              dell'Informazione  * 4. The names of these contributors may not be used to endorse or promote  *  products derived from this software without specific prior written  *  permission.  *  * THIS SOFTWARE IS PROVIDED BY THE CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Works for FreeBSD 1.1.5  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_B004_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_B004_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/*  * device status FLAGS  */
end_comment

begin_define
define|#
directive|define
name|B004_EXIST
value|0x0001
end_define

begin_comment
comment|/* Is a B004-Board with at least one 					   Transputer present ? */
end_comment

begin_define
define|#
directive|define
name|B004_BUSY
value|0x0002
end_define

begin_comment
comment|/* Is the B004-board in use ? */
end_comment

begin_comment
comment|/*  * IOCTL numbers  */
end_comment

begin_define
define|#
directive|define
name|B004RESET
value|_IO  ('Q', 0)
end_define

begin_comment
comment|/* Reset transputer(s) */
end_comment

begin_define
define|#
directive|define
name|B004WRITEABLE
value|_IOR ('Q', 1, int)
end_define

begin_comment
comment|/* Return C012 Output Ready */
end_comment

begin_define
define|#
directive|define
name|B004READABLE
value|_IOR ('Q', 2, int)
end_define

begin_comment
comment|/* Return C012 Data Present */
end_comment

begin_define
define|#
directive|define
name|B004ANALYSE
value|_IO  ('Q', 3)
end_define

begin_comment
comment|/* Switch transputer(s) to ANALYSE mode */
end_comment

begin_define
define|#
directive|define
name|B004ERROR
value|_IOR ('Q', 4, int)
end_define

begin_comment
comment|/* Return 1 on ERROR set */
end_comment

begin_define
define|#
directive|define
name|B004TIMEOUT
value|_IOW ('Q', 5, int)
end_define

begin_comment
comment|/* Set TIMEOUT for subsequent writing or 				   reading call, value in ticks, initial 				   0 = no timeout (read/write blocking) 				   "open" sets timeout to 0 */
end_comment

begin_define
define|#
directive|define
name|B004_INIT_TIMEOUT
value|0
end_define

begin_comment
comment|/* No timeout yet */
end_comment

begin_comment
comment|/*  * Registers DISPLACEMENT  */
end_comment

begin_define
define|#
directive|define
name|B004_IDR_OFFSET
value|0
end_define

begin_comment
comment|/* Input Data Register */
end_comment

begin_define
define|#
directive|define
name|B004_ODR_OFFSET
value|1
end_define

begin_comment
comment|/* Output Data Register */
end_comment

begin_define
define|#
directive|define
name|B004_ISR_OFFSET
value|2
end_define

begin_comment
comment|/* Input Status Register */
end_comment

begin_define
define|#
directive|define
name|B004_OSR_OFFSET
value|3
end_define

begin_comment
comment|/* Output Status Register */
end_comment

begin_define
define|#
directive|define
name|B004_RESET_OFFSET
value|16
end_define

begin_comment
comment|/* Reset/Error Register */
end_comment

begin_define
define|#
directive|define
name|B004_ERROR_OFFSET
value|B004_RESET_OFFSET
end_define

begin_define
define|#
directive|define
name|B004_ANALYSE_OFFSET
value|17
end_define

begin_comment
comment|/* Analyse Register */
end_comment

begin_define
define|#
directive|define
name|B008_DMA_OFFSET
value|18
end_define

begin_comment
comment|/* B008: DMA request register */
end_comment

begin_define
define|#
directive|define
name|B008_INT_OFFSET
value|19
end_define

begin_comment
comment|/* B008: Interrupt control reg */
end_comment

begin_struct
struct|struct
name|b004_struct
block|{
name|int
name|flags
decl_stmt|;
comment|/* various flags */
name|int
name|idr
decl_stmt|;
comment|/* address of the input data register */
name|int
name|odr
decl_stmt|;
comment|/* address if the output data register */
name|int
name|isr
decl_stmt|;
comment|/* address of the input status register */
name|int
name|osr
decl_stmt|;
comment|/* address of the output status register */
name|unsigned
name|int
name|timeout
decl_stmt|;
comment|/* timeout for writing/reading the link */
name|int
name|boardtype
decl_stmt|;
comment|/* what kind of board is installed */
name|void
modifier|*
name|devfs_token
index|[
literal|8
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/* tokens for 4 types for 8 ports */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Id's for the supported boards  */
end_comment

begin_define
define|#
directive|define
name|B004
value|1
end_define

begin_define
define|#
directive|define
name|B008
value|2
end_define

begin_comment
comment|/*  * Defines for easier access to the b004_table.  */
end_comment

begin_define
define|#
directive|define
name|B004_F
parameter_list|(
name|minor
parameter_list|)
value|b004_table[minor].flags
end_define

begin_define
define|#
directive|define
name|B004_TIMEOUT
parameter_list|(
name|minor
parameter_list|)
value|b004_table[minor].timeout
end_define

begin_define
define|#
directive|define
name|B004_BASE
parameter_list|(
name|minor
parameter_list|)
value|B004_IDR(minor)
end_define

begin_define
define|#
directive|define
name|B004_IDR
parameter_list|(
name|minor
parameter_list|)
value|b004_table[minor].idr
end_define

begin_define
define|#
directive|define
name|B004_ODR
parameter_list|(
name|minor
parameter_list|)
value|b004_table[minor].odr
end_define

begin_define
define|#
directive|define
name|B004_ISR
parameter_list|(
name|minor
parameter_list|)
value|b004_table[minor].isr
end_define

begin_define
define|#
directive|define
name|B004_OSR
parameter_list|(
name|minor
parameter_list|)
value|b004_table[minor].osr
end_define

begin_define
define|#
directive|define
name|B004_WAIT
parameter_list|(
name|minor
parameter_list|)
value|b004_table[minor].wait
end_define

begin_define
define|#
directive|define
name|B004_BOARDTYPE
parameter_list|(
name|minor
parameter_list|)
value|b004_table[minor].boardtype
end_define

begin_comment
comment|/*  * Additional defines for B008-boards  */
end_comment

begin_define
define|#
directive|define
name|B008_DMA
parameter_list|(
name|minor
parameter_list|)
value|b004_table[minor].int
end_define

begin_define
define|#
directive|define
name|B008_INT
parameter_list|(
name|minor
parameter_list|)
value|b004_table[minor].dma
end_define

begin_comment
comment|/*  * Number of tries to access isr or osr before reading or writing sleeps  */
end_comment

begin_define
define|#
directive|define
name|B004_MAXTRY
value|200
end_define

begin_comment
comment|/*  * Maximum number of bytes to transfer at once  */
end_comment

begin_define
define|#
directive|define
name|B004_MAX_BYTES
value|2048
end_define

begin_comment
comment|/*  * bit defines for C012 status ports at base + 2/3  * accessed with B004_IS, B004_OS, which gets the byte...  */
end_comment

begin_define
define|#
directive|define
name|B004_READBYTE
value|1
end_define

begin_define
define|#
directive|define
name|B004_WRITEBYTE
value|1
end_define

begin_comment
comment|/*  * bit defines for C012 reset/error port at base + 16  */
end_comment

begin_define
define|#
directive|define
name|B004_ASSERT_RESET
value|0x01
end_define

begin_comment
comment|/* resetting the transputer */
end_comment

begin_define
define|#
directive|define
name|B004_DEASSERT_RESET
value|0x00
end_define

begin_define
define|#
directive|define
name|B004_TEST_ERROR
value|0x01
end_define

begin_comment
comment|/* for testing the transputer's error flag */
end_comment

begin_comment
comment|/*  * bit defines for C012 analyse port at base + 17  */
end_comment

begin_define
define|#
directive|define
name|B004_ASSERT_ANALYSE
value|0x01
end_define

begin_comment
comment|/* switch transputer to analyse-mode */
end_comment

begin_define
define|#
directive|define
name|B004_DEASSERT_ANALYSE
value|0x00
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_I386_ISA_B004_H_ */
end_comment

end_unit

