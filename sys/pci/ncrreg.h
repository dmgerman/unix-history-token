begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************** ** ** $FreeBSD$ ** **  Device driver for the   NCR 53C810   PCI-SCSI-Controller. ** **  386bsd / FreeBSD / NetBSD ** **------------------------------------------------------------------------- ** **  Written for 386bsd and FreeBSD by **	wolf@cologne.de		Wolfgang Stanglmeier **	se@mi.Uni-Koeln.de	Stefan Esser ** **  Ported to NetBSD by **	mycroft@gnu.ai.mit.edu ** **------------------------------------------------------------------------- ** ** Copyright (c) 1994 Wolfgang Stanglmeier.  All rights reserved. ** ** Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions ** are met: ** 1. Redistributions of source code must retain the above copyright **    notice, this list of conditions and the following disclaimer. ** 2. Redistributions in binary form must reproduce the above copyright **    notice, this list of conditions and the following disclaimer in the **    documentation and/or other materials provided with the distribution. ** 3. The name of the author may not be used to endorse or promote products **    derived from this software without specific prior written permission. ** ** THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR ** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES ** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. ** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, ** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT ** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF ** THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ** *************************************************************************** */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NCR_REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__NCR_REG_H__
end_define

begin_comment
comment|/*----------------------------------------------------------------- ** **	The ncr 53c810 register structure. ** **----------------------------------------------------------------- */
end_comment

begin_struct
struct|struct
name|ncr_reg
block|{
comment|/*00*/
name|u_char
name|nc_scntl0
decl_stmt|;
comment|/* full arb., ena parity, par->ATN  */
comment|/*01*/
name|u_char
name|nc_scntl1
decl_stmt|;
comment|/* no reset                         */
define|#
directive|define
name|ISCON
value|0x10
comment|/* connected to scsi		    */
define|#
directive|define
name|CRST
value|0x08
comment|/* force reset                      */
comment|/*02*/
name|u_char
name|nc_scntl2
decl_stmt|;
comment|/* no disconnect expected           */
define|#
directive|define
name|SDU
value|0x80
comment|/* cmd: disconnect will raise error */
define|#
directive|define
name|CHM
value|0x40
comment|/* sta: chained mode                */
define|#
directive|define
name|WSS
value|0x08
comment|/* sta: wide scsi send           [W]*/
define|#
directive|define
name|WSR
value|0x01
comment|/* sta: wide scsi received       [W]*/
comment|/*03*/
name|u_char
name|nc_scntl3
decl_stmt|;
comment|/* cnf system clock dependent       */
define|#
directive|define
name|EWS
value|0x08
comment|/* cmd: enable wide scsi         [W]*/
comment|/*04*/
name|u_char
name|nc_scid
decl_stmt|;
comment|/* cnf host adapter scsi address    */
define|#
directive|define
name|RRE
value|0x40
comment|/* r/w:e enable response to resel.  */
define|#
directive|define
name|SRE
value|0x20
comment|/* r/w:e enable response to select  */
comment|/*05*/
name|u_char
name|nc_sxfer
decl_stmt|;
comment|/* ### Sync speed and count         */
comment|/*06*/
name|u_char
name|nc_sdid
decl_stmt|;
comment|/* ### Destination-ID               */
comment|/*07*/
name|u_char
name|nc_gpreg
decl_stmt|;
comment|/* ??? IO-Pins                      */
comment|/*08*/
name|u_char
name|nc_sfbr
decl_stmt|;
comment|/* ### First byte in phase          */
comment|/*09*/
name|u_char
name|nc_socl
decl_stmt|;
define|#
directive|define
name|CREQ
value|0x80
comment|/* r/w: SCSI-REQ                    */
define|#
directive|define
name|CACK
value|0x40
comment|/* r/w: SCSI-ACK                    */
define|#
directive|define
name|CBSY
value|0x20
comment|/* r/w: SCSI-BSY                    */
define|#
directive|define
name|CSEL
value|0x10
comment|/* r/w: SCSI-SEL                    */
define|#
directive|define
name|CATN
value|0x08
comment|/* r/w: SCSI-ATN                    */
define|#
directive|define
name|CMSG
value|0x04
comment|/* r/w: SCSI-MSG                    */
define|#
directive|define
name|CC_D
value|0x02
comment|/* r/w: SCSI-C_D                    */
define|#
directive|define
name|CI_O
value|0x01
comment|/* r/w: SCSI-I_O                    */
comment|/*0a*/
name|u_char
name|nc_ssid
decl_stmt|;
comment|/*0b*/
name|u_char
name|nc_sbcl
decl_stmt|;
comment|/*0c*/
name|u_char
name|nc_dstat
decl_stmt|;
define|#
directive|define
name|DFE
value|0x80
comment|/* sta: dma fifo empty              */
define|#
directive|define
name|MDPE
value|0x40
comment|/* int: master data parity error    */
define|#
directive|define
name|BF
value|0x20
comment|/* int: script: bus fault           */
define|#
directive|define
name|ABRT
value|0x10
comment|/* int: script: command aborted     */
define|#
directive|define
name|SSI
value|0x08
comment|/* int: script: single step         */
define|#
directive|define
name|SIR
value|0x04
comment|/* int: script: interrupt instruct. */
define|#
directive|define
name|IID
value|0x01
comment|/* int: script: illegal instruct.   */
comment|/*0d*/
name|u_char
name|nc_sstat0
decl_stmt|;
define|#
directive|define
name|ILF
value|0x80
comment|/* sta: data in SIDL register lsb   */
define|#
directive|define
name|ORF
value|0x40
comment|/* sta: data in SODR register lsb   */
define|#
directive|define
name|OLF
value|0x20
comment|/* sta: data in SODL register lsb   */
define|#
directive|define
name|AIP
value|0x10
comment|/* sta: arbitration in progress     */
define|#
directive|define
name|LOA
value|0x08
comment|/* sta: arbitration lost            */
define|#
directive|define
name|WOA
value|0x04
comment|/* sta: arbitration won             */
define|#
directive|define
name|IRST
value|0x02
comment|/* sta: scsi reset signal           */
define|#
directive|define
name|SDP
value|0x01
comment|/* sta: scsi parity signal          */
comment|/*0e*/
name|u_char
name|nc_sstat1
decl_stmt|;
define|#
directive|define
name|FF3210
value|0xf0
comment|/* sta: bytes in the scsi fifo      */
comment|/*0f*/
name|u_char
name|nc_sstat2
decl_stmt|;
define|#
directive|define
name|ILF1
value|0x80
comment|/* sta: data in SIDL register msb[W]*/
define|#
directive|define
name|ORF1
value|0x40
comment|/* sta: data in SODR register msb[W]*/
define|#
directive|define
name|OLF1
value|0x20
comment|/* sta: data in SODL register msb[W]*/
define|#
directive|define
name|LDSC
value|0x02
comment|/* sta: disconnect& reconnect      */
comment|/*10*/
name|u_int32_t
name|nc_dsa
decl_stmt|;
comment|/* --> Base page                    */
comment|/*14*/
name|u_char
name|nc_istat
decl_stmt|;
comment|/* --> Main Command and status      */
define|#
directive|define
name|CABRT
value|0x80
comment|/* cmd: abort current operation     */
define|#
directive|define
name|SRST
value|0x40
comment|/* mod: reset chip                  */
define|#
directive|define
name|SIGP
value|0x20
comment|/* r/w: message from host to ncr    */
define|#
directive|define
name|SEM
value|0x10
comment|/* r/w: message between host + ncr  */
define|#
directive|define
name|CON
value|0x08
comment|/* sta: connected to scsi           */
define|#
directive|define
name|INTF
value|0x04
comment|/* sta: int on the fly (reset by wr)*/
define|#
directive|define
name|SIP
value|0x02
comment|/* sta: scsi-interrupt              */
define|#
directive|define
name|DIP
value|0x01
comment|/* sta: host/script interrupt       */
comment|/*15*/
name|u_char
name|nc_15_
decl_stmt|;
comment|/*16*/
name|u_char
name|nc_16_
decl_stmt|;
comment|/*17*/
name|u_char
name|nc_17_
decl_stmt|;
comment|/*18*/
name|u_char
name|nc_ctest0
decl_stmt|;
comment|/*19*/
name|u_char
name|nc_ctest1
decl_stmt|;
comment|/*1a*/
name|u_char
name|nc_ctest2
decl_stmt|;
define|#
directive|define
name|CSIGP
value|0x40
comment|/*1b*/
name|u_char
name|nc_ctest3
decl_stmt|;
define|#
directive|define
name|FLF
value|0x08
comment|/* cmd: flush dma fifo              */
define|#
directive|define
name|CLF
value|0x04
comment|/* cmd: clear dma fifo		    */
define|#
directive|define
name|FM
value|0x02
comment|/* mod: fetch pin mode              */
define|#
directive|define
name|WRIE
value|0x01
comment|/* mod: write and invalidate enable */
comment|/*1c*/
name|u_int32_t
name|nc_temp
decl_stmt|;
comment|/* ### Temporary stack              */
comment|/*20*/
name|u_char
name|nc_dfifo
decl_stmt|;
comment|/*21*/
name|u_char
name|nc_ctest4
decl_stmt|;
define|#
directive|define
name|BDIS
value|0x80
comment|/* mod: burst disable               */
define|#
directive|define
name|MPEE
value|0x08
comment|/* mod: master parity error enable  */
comment|/*22*/
name|u_char
name|nc_ctest5
decl_stmt|;
define|#
directive|define
name|DFS
value|0x20
comment|/* mod: dma fifo size               */
comment|/*23*/
name|u_char
name|nc_ctest6
decl_stmt|;
comment|/*24*/
name|u_int32_t
name|nc_dbc
decl_stmt|;
comment|/* ### Byte count and command       */
comment|/*28*/
name|u_int32_t
name|nc_dnad
decl_stmt|;
comment|/* ### Next command register        */
comment|/*2c*/
name|u_int32_t
name|nc_dsp
decl_stmt|;
comment|/* --> Script Pointer               */
comment|/*30*/
name|u_int32_t
name|nc_dsps
decl_stmt|;
comment|/* --> Script pointer save/opcode#2 */
comment|/*34*/
name|u_int32_t
name|nc_scratcha
decl_stmt|;
comment|/* ??? Temporary register a         */
comment|/*38*/
name|u_char
name|nc_dmode
decl_stmt|;
define|#
directive|define
name|BL_2
value|0x80
comment|/* mod: burst length shift value +2 */
define|#
directive|define
name|BL_1
value|0x40
comment|/* mod: burst length shift value +1 */
define|#
directive|define
name|ERL
value|0x08
comment|/* mod: enable read line            */
define|#
directive|define
name|ERMP
value|0x04
comment|/* mod: enable read multiple        */
define|#
directive|define
name|BOF
value|0x02
comment|/* mod: burst op code fetch         */
comment|/*39*/
name|u_char
name|nc_dien
decl_stmt|;
comment|/*3a*/
name|u_char
name|nc_dwt
decl_stmt|;
comment|/*3b*/
name|u_char
name|nc_dcntl
decl_stmt|;
comment|/* --> Script execution control     */
define|#
directive|define
name|CLSE
value|0x80
comment|/* mod: cache line size enable      */
define|#
directive|define
name|PFF
value|0x40
comment|/* cmd: pre-fetch flush             */
define|#
directive|define
name|PFEN
value|0x20
comment|/* mod: pre-fetch enable            */
define|#
directive|define
name|SSM
value|0x10
comment|/* mod: single step mode            */
define|#
directive|define
name|IRQM
value|0x08
comment|/* mod: irq mode (1 = totem pole !) */
define|#
directive|define
name|STD
value|0x04
comment|/* cmd: start dma mode              */
define|#
directive|define
name|IRQD
value|0x02
comment|/* mod: irq disable                 */
define|#
directive|define
name|NOCOM
value|0x01
comment|/* cmd: protect sfbr while reselect */
comment|/*3c*/
name|u_int32_t
name|nc_adder
decl_stmt|;
comment|/*40*/
name|u_short
name|nc_sien
decl_stmt|;
comment|/* -->: interrupt enable            */
comment|/*42*/
name|u_short
name|nc_sist
decl_stmt|;
comment|/*<--: interrupt status            */
define|#
directive|define
name|STO
value|0x0400
comment|/* sta: timeout (select)            */
define|#
directive|define
name|GEN
value|0x0200
comment|/* sta: timeout (general)           */
define|#
directive|define
name|HTH
value|0x0100
comment|/* sta: timeout (handshake)         */
define|#
directive|define
name|MA
value|0x80
comment|/* sta: phase mismatch              */
define|#
directive|define
name|CMP
value|0x40
comment|/* sta: arbitration complete        */
define|#
directive|define
name|SEL
value|0x20
comment|/* sta: selected by another device  */
define|#
directive|define
name|RSL
value|0x10
comment|/* sta: reselected by another device*/
define|#
directive|define
name|SGE
value|0x08
comment|/* sta: gross error (over/underflow)*/
define|#
directive|define
name|UDC
value|0x04
comment|/* sta: unexpected disconnect       */
define|#
directive|define
name|RST
value|0x02
comment|/* sta: scsi bus reset detected     */
define|#
directive|define
name|PAR
value|0x01
comment|/* sta: scsi parity error           */
comment|/*44*/
name|u_char
name|nc_slpar
decl_stmt|;
comment|/*45*/
name|u_char
name|nc_swide
decl_stmt|;
comment|/*46*/
name|u_char
name|nc_macntl
decl_stmt|;
comment|/*47*/
name|u_char
name|nc_gpcntl
decl_stmt|;
comment|/*48*/
name|u_char
name|nc_stime0
decl_stmt|;
comment|/* cmd: timeout for select&handshake*/
comment|/*49*/
name|u_char
name|nc_stime1
decl_stmt|;
comment|/* cmd: timeout user defined        */
comment|/*4a*/
name|u_short
name|nc_respid
decl_stmt|;
comment|/* sta: Reselect-IDs                */
comment|/*4c*/
name|u_char
name|nc_stest0
decl_stmt|;
comment|/*4d*/
name|u_char
name|nc_stest1
decl_stmt|;
define|#
directive|define
name|DBLEN
value|0x08
comment|/* clock doubler running		*/
define|#
directive|define
name|DBLSEL
value|0x04
comment|/* clock doubler selected		*/
comment|/*4e*/
name|u_char
name|nc_stest2
decl_stmt|;
define|#
directive|define
name|ROF
value|0x40
comment|/* reset scsi offset (after gross error!) */
define|#
directive|define
name|EXT
value|0x02
comment|/* extended filtering                     */
comment|/*4f*/
name|u_char
name|nc_stest3
decl_stmt|;
define|#
directive|define
name|TE
value|0x80
comment|/* c: tolerAnt enable */
define|#
directive|define
name|HSC
value|0x20
comment|/* c: Halt SCSI Clock */
define|#
directive|define
name|CSF
value|0x02
comment|/* c: clear scsi fifo */
comment|/*50*/
name|u_short
name|nc_sidl
decl_stmt|;
comment|/* Lowlevel: latched from scsi data */
comment|/*52*/
name|u_char
name|nc_stest4
decl_stmt|;
define|#
directive|define
name|SMODE
value|0xc0
comment|/* SCSI bus mode      (895/6 only) */
define|#
directive|define
name|SMODE_HVD
value|0x40
comment|/* High Voltage Differential       */
define|#
directive|define
name|SMODE_SE
value|0x80
comment|/* Single Ended                    */
define|#
directive|define
name|SMODE_LVD
value|0xc0
comment|/* Low Voltage Differential        */
define|#
directive|define
name|LCKFRQ
value|0x20
comment|/* Frequency Lock (895/6 only)     */
comment|/*53*/
name|u_char
name|nc_53_
decl_stmt|;
comment|/*54*/
name|u_short
name|nc_sodl
decl_stmt|;
comment|/* Lowlevel: data out to scsi data  */
comment|/*56*/
name|u_short
name|nc_56_
decl_stmt|;
comment|/*58*/
name|u_short
name|nc_sbdl
decl_stmt|;
comment|/* Lowlevel: data from scsi data    */
comment|/*5a*/
name|u_short
name|nc_5a_
decl_stmt|;
comment|/*5c*/
name|u_char
name|nc_scr0
decl_stmt|;
comment|/* Working register B               */
comment|/*5d*/
name|u_char
name|nc_scr1
decl_stmt|;
comment|/*                                  */
comment|/*5e*/
name|u_char
name|nc_scr2
decl_stmt|;
comment|/*                                  */
comment|/*5f*/
name|u_char
name|nc_scr3
decl_stmt|;
comment|/*                                  */
comment|/*60*/
block|}
struct|;
end_struct

begin_comment
comment|/*----------------------------------------------------------- ** **	Utility macros for the script. ** **----------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|REGJ
parameter_list|(
name|p
parameter_list|,
name|r
parameter_list|)
value|(offsetof(struct ncr_reg, p ## r))
end_define

begin_define
define|#
directive|define
name|REG
parameter_list|(
name|r
parameter_list|)
value|REGJ (nc_, r)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_MODE
end_ifndef

begin_define
define|#
directive|define
name|TARGET_MODE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|u_int32_t
name|ncrcmd
typedef|;
end_typedef

begin_comment
comment|/*----------------------------------------------------------- ** **	SCSI phases ** **----------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|SCR_DATA_OUT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SCR_DATA_IN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SCR_COMMAND
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SCR_STATUS
value|0x03000000
end_define

begin_define
define|#
directive|define
name|SCR_ILG_OUT
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SCR_ILG_IN
value|0x05000000
end_define

begin_define
define|#
directive|define
name|SCR_MSG_OUT
value|0x06000000
end_define

begin_define
define|#
directive|define
name|SCR_MSG_IN
value|0x07000000
end_define

begin_comment
comment|/*----------------------------------------------------------- ** **	Data transfer via SCSI. ** **----------------------------------------------------------- ** **	MOVE_ABS (LEN) **<<start address>> ** **	MOVE_IND (LEN) **<<dnad_offset>> ** **	MOVE_TBL **<<dnad_offset>> ** **----------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|SCR_MOVE_ABS
parameter_list|(
name|l
parameter_list|)
value|((0x08000000 ^ (TARGET_MODE<< 1ul)) | (l))
end_define

begin_define
define|#
directive|define
name|SCR_MOVE_IND
parameter_list|(
name|l
parameter_list|)
value|((0x28000000 ^ (TARGET_MODE<< 1ul)) | (l))
end_define

begin_define
define|#
directive|define
name|SCR_MOVE_TBL
value|(0x18000000 ^ (TARGET_MODE<< 1ul))
end_define

begin_struct
struct|struct
name|scr_tblmove
block|{
name|u_int32_t
name|size
decl_stmt|;
name|u_int32_t
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*----------------------------------------------------------- ** **	Selection ** **----------------------------------------------------------- ** **	SEL_ABS | SCR_ID (0..7)     [ | REL_JMP] **<<alternate_address>> ** **	SEL_TBL |<< dnad_offset>>  [ | REL_JMP] **<<alternate_address>> ** **----------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|SCR_SEL_ABS
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SCR_SEL_ABS_ATN
value|0x41000000
end_define

begin_define
define|#
directive|define
name|SCR_SEL_TBL
value|0x42000000
end_define

begin_define
define|#
directive|define
name|SCR_SEL_TBL_ATN
value|0x43000000
end_define

begin_struct
struct|struct
name|scr_tblsel
block|{
name|u_char
name|sel_0
decl_stmt|;
name|u_char
name|sel_sxfer
decl_stmt|;
name|u_char
name|sel_id
decl_stmt|;
name|u_char
name|sel_scntl3
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCR_JMP_REL
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SCR_ID
parameter_list|(
name|id
parameter_list|)
value|(((u_int32_t)(id))<< 16)
end_define

begin_comment
comment|/*----------------------------------------------------------- ** **	Waiting for Disconnect or Reselect ** **----------------------------------------------------------- ** **	WAIT_DISC **	dummy:<<alternate_address>> ** **	WAIT_RESEL **<<alternate_address>> ** **----------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|SCR_WAIT_DISC
value|0x48000000
end_define

begin_define
define|#
directive|define
name|SCR_WAIT_RESEL
value|0x50000000
end_define

begin_comment
comment|/*----------------------------------------------------------- ** **	Bit Set / Reset ** **----------------------------------------------------------- ** **	SET (flags {|.. }) ** **	CLR (flags {|.. }) ** **----------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|SCR_SET
parameter_list|(
name|f
parameter_list|)
value|(0x58000000 | (f))
end_define

begin_define
define|#
directive|define
name|SCR_CLR
parameter_list|(
name|f
parameter_list|)
value|(0x60000000 | (f))
end_define

begin_define
define|#
directive|define
name|SCR_CARRY
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SCR_TRG
value|0x00000200
end_define

begin_define
define|#
directive|define
name|SCR_ACK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|SCR_ATN
value|0x00000008
end_define

begin_comment
comment|/*----------------------------------------------------------- ** **	Memory to memory move ** **----------------------------------------------------------- ** **	COPY (bytecount) **<< source_address>> **<< destination_address>> ** **	SCR_COPY   sets the NO FLUSH option by default. **	SCR_COPY_F does not set this option. ** **	For chips which do not support this option, **	ncr_copy_and_bind() will remove this bit. **----------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|SCR_NO_FLUSH
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SCR_COPY
parameter_list|(
name|n
parameter_list|)
value|(0xc0000000 | SCR_NO_FLUSH | (n))
end_define

begin_define
define|#
directive|define
name|SCR_COPY_F
parameter_list|(
name|n
parameter_list|)
value|(0xc0000000 | (n))
end_define

begin_comment
comment|/*----------------------------------------------------------- ** **	Register move and binary operations ** **----------------------------------------------------------- ** **	SFBR_REG (reg, op, data)        reg  = SFBR op data **<< 0>> ** **	REG_SFBR (reg, op, data)        SFBR = reg op data **<< 0>> ** **	REG_REG  (reg, op, data)        reg  = reg op data **<< 0>> ** **----------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|SCR_REG_OFS
parameter_list|(
name|ofs
parameter_list|)
value|((ofs)<< 16ul)
end_define

begin_define
define|#
directive|define
name|SCR_SFBR_REG
parameter_list|(
name|reg
parameter_list|,
name|op
parameter_list|,
name|data
parameter_list|)
define|\
value|(0x68000000 | (SCR_REG_OFS(REG(reg))) | (op) | ((data)<<8ul))
end_define

begin_define
define|#
directive|define
name|SCR_REG_SFBR
parameter_list|(
name|reg
parameter_list|,
name|op
parameter_list|,
name|data
parameter_list|)
define|\
value|(0x70000000 | (SCR_REG_OFS(REG(reg))) | (op) | ((data)<<8ul))
end_define

begin_define
define|#
directive|define
name|SCR_REG_REG
parameter_list|(
name|reg
parameter_list|,
name|op
parameter_list|,
name|data
parameter_list|)
define|\
value|(0x78000000 | (SCR_REG_OFS(REG(reg))) | (op) | ((data)<<8ul))
end_define

begin_define
define|#
directive|define
name|SCR_LOAD
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SCR_SHL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SCR_OR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SCR_XOR
value|0x03000000
end_define

begin_define
define|#
directive|define
name|SCR_AND
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SCR_SHR
value|0x05000000
end_define

begin_define
define|#
directive|define
name|SCR_ADD
value|0x06000000
end_define

begin_define
define|#
directive|define
name|SCR_ADDC
value|0x07000000
end_define

begin_comment
comment|/*----------------------------------------------------------- ** **	FROM_REG (reg)		  reg  = SFBR **<< 0>> ** **	TO_REG	 (reg)		  SFBR = reg **<< 0>> ** **	LOAD_REG (reg, data)	  reg  =<data> **<< 0>> ** **	LOAD_SFBR(data) 	  SFBR =<data> **<< 0>> ** **----------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|SCR_FROM_REG
parameter_list|(
name|reg
parameter_list|)
define|\
value|SCR_REG_SFBR(reg,SCR_OR,0)
end_define

begin_define
define|#
directive|define
name|SCR_TO_REG
parameter_list|(
name|reg
parameter_list|)
define|\
value|SCR_SFBR_REG(reg,SCR_OR,0)
end_define

begin_define
define|#
directive|define
name|SCR_LOAD_REG
parameter_list|(
name|reg
parameter_list|,
name|data
parameter_list|)
define|\
value|SCR_REG_REG(reg,SCR_LOAD,data)
end_define

begin_define
define|#
directive|define
name|SCR_LOAD_SFBR
parameter_list|(
name|data
parameter_list|)
define|\
value|(SCR_REG_SFBR (gpreg, SCR_LOAD, data))
end_define

begin_comment
comment|/*----------------------------------------------------------- ** **	Waiting for Disconnect or Reselect ** **----------------------------------------------------------- ** **	JUMP            [ | IFTRUE/IFFALSE ( ... ) ] **<<address>> ** **	JUMPR           [ | IFTRUE/IFFALSE ( ... ) ] **<<distance>> ** **	CALL            [ | IFTRUE/IFFALSE ( ... ) ] **<<address>> ** **	CALLR           [ | IFTRUE/IFFALSE ( ... ) ] **<<distance>> ** **	RETURN          [ | IFTRUE/IFFALSE ( ... ) ] **<<dummy>> ** **	INT             [ | IFTRUE/IFFALSE ( ... ) ] **<<ident>> ** **	INT_FLY         [ | IFTRUE/IFFALSE ( ... ) ] **<<ident>> ** **	Conditions: **	     WHEN (phase) **	     IF   (phase) **	     CARRY **	     DATA (data, mask) ** **----------------------------------------------------------- */
end_comment

begin_define
define|#
directive|define
name|SCR_NO_OP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SCR_JUMP
value|0x80080000
end_define

begin_define
define|#
directive|define
name|SCR_JUMPR
value|0x80880000
end_define

begin_define
define|#
directive|define
name|SCR_CALL
value|0x88080000
end_define

begin_define
define|#
directive|define
name|SCR_CALLR
value|0x88880000
end_define

begin_define
define|#
directive|define
name|SCR_RETURN
value|0x90080000
end_define

begin_define
define|#
directive|define
name|SCR_INT
value|0x98080000
end_define

begin_define
define|#
directive|define
name|SCR_INT_FLY
value|0x98180000
end_define

begin_define
define|#
directive|define
name|IFFALSE
parameter_list|(
name|arg
parameter_list|)
value|(0x00080000 | (arg))
end_define

begin_define
define|#
directive|define
name|IFTRUE
parameter_list|(
name|arg
parameter_list|)
value|(0x00000000 | (arg))
end_define

begin_define
define|#
directive|define
name|WHEN
parameter_list|(
name|phase
parameter_list|)
value|(0x00030000 | (phase))
end_define

begin_define
define|#
directive|define
name|IF
parameter_list|(
name|phase
parameter_list|)
value|(0x00020000 | (phase))
end_define

begin_define
define|#
directive|define
name|DATA
parameter_list|(
name|D
parameter_list|)
value|(0x00040000 | ((D)& 0xff))
end_define

begin_define
define|#
directive|define
name|MASK
parameter_list|(
name|D
parameter_list|,
name|M
parameter_list|)
value|(0x00040000 | (((M ^ 0xff)& 0xff)<< 8ul)|((D)& 0xff))
end_define

begin_define
define|#
directive|define
name|CARRYSET
value|(0x00200000)
end_define

begin_comment
comment|/*----------------------------------------------------------- ** **	SCSI  constants. ** **----------------------------------------------------------- */
end_comment

begin_comment
comment|/* **	Messages */
end_comment

begin_define
define|#
directive|define
name|M_X_MODIFY_DP
value|(0x00)
end_define

begin_comment
comment|/* **	Status */
end_comment

begin_define
define|#
directive|define
name|SCSI_STATUS_ILLEGAL
value|(0xff)
end_define

begin_define
define|#
directive|define
name|SCSI_STATUS_SENSE
value|(0x80)
end_define

begin_comment
comment|/* **	Bits defining chip features. **	For now only some of them are used, since we explicitely  **	deal with PCI device id and revision id. */
end_comment

begin_define
define|#
directive|define
name|FE_LED0
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|FE_WIDE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|FE_ULTRA
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|FE_ULTRA2
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|FE_DBLR
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|FE_QUAD
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|FE_ERL
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|FE_CLSE
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|FE_WRIE
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|FE_ERMP
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|FE_BOF
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|FE_DFS
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|FE_PFEN
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|FE_LDSTR
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|FE_RAM
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|FE_CLK80
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|FE_DIFF
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|FE_BIOS
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|FE_CACHE_SET
value|(FE_ERL|FE_CLSE|FE_WRIE|FE_ERMP)
end_define

begin_define
define|#
directive|define
name|FE_SCSI_SET
value|(FE_WIDE|FE_ULTRA|FE_ULTRA2|FE_DBLR|FE_QUAD|F_CLK80)
end_define

begin_define
define|#
directive|define
name|FE_SPECIAL_SET
value|(FE_CACHE_SET|FE_BOF|FE_DFS|FE_LDSTR|FE_PFEN|FE_RAM)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__NCR_REG_H__*/
end_comment

end_unit

