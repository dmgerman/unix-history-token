begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * @(#)crl.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/****************************************************************  *                                                              *  *        Licensed from Digital Equipment Corporation           *  *                       Copyright (c)                          *  *               Digital Equipment Corporation                  *  *                   Maynard, Massachusetts                     *  *                         1985, 1986                           *  *                    All rights reserved.                      *  *                                                              *  *        The Information in this software is subject to change *  *   without notice and should not be construed as a commitment *  *   by  Digital  Equipment  Corporation.   Digital   makes  no *  *   representations about the suitability of this software for *  *   any purpose.  It is supplied "As Is" without expressed  or *  *   implied  warranty.                                         *  *                                                              *  *        If the Regents of the University of California or its *  *   licensees modify the software in a manner creating         *  *   diriviative copyright rights, appropriate copyright        *  *   legends may be placed on  the drivative work in addition   *  *   to that set forth above.                                   *  ****************************************************************/
end_comment

begin_if
if|#
directive|if
name|VAX8600
end_if

begin_comment
comment|/*  * Console RL02 status of current transfer (read only)  */
end_comment

begin_define
define|#
directive|define
name|CRL_S_XCMPLT
value|1
end_define

begin_comment
comment|/* transaction complete */
end_comment

begin_define
define|#
directive|define
name|CRL_S_XCONT
value|2
end_define

begin_comment
comment|/* continue transaction */
end_comment

begin_define
define|#
directive|define
name|CRL_S_ABORT
value|3
end_define

begin_comment
comment|/* transation abort */
end_comment

begin_define
define|#
directive|define
name|CRL_S_RETSTS
value|4
end_define

begin_comment
comment|/* return device status */
end_comment

begin_define
define|#
directive|define
name|CRL_S_HNDSHK
value|0x80
end_define

begin_comment
comment|/* handshake err during transaction */
end_comment

begin_define
define|#
directive|define
name|CRL_S_HWERR
value|0x81
end_define

begin_comment
comment|/* hardware err during transaction */
end_comment

begin_comment
comment|/*  * Console RL02 function codes  */
end_comment

begin_define
define|#
directive|define
name|CRL_F_NOOP
value|0
end_define

begin_comment
comment|/* No operation */
end_comment

begin_define
define|#
directive|define
name|CRL_F_RSTSTS
value|2
end_define

begin_comment
comment|/* reset and return device status */
end_comment

begin_define
define|#
directive|define
name|CRL_F_ABORT
value|3
end_define

begin_comment
comment|/* abort transfer */
end_comment

begin_define
define|#
directive|define
name|CRL_F_RETSTS
value|4
end_define

begin_comment
comment|/* read device status */
end_comment

begin_define
define|#
directive|define
name|CRL_F_WRITE
value|5
end_define

begin_comment
comment|/* write block data */
end_comment

begin_define
define|#
directive|define
name|CRL_F_READ
value|6
end_define

begin_comment
comment|/* read block data */
end_comment

begin_comment
comment|/*  * Console sectoring information.  * The console understands the rl02 as having 512 byte sectors.  */
end_comment

begin_define
define|#
directive|define
name|CRLBYSEC
value|512
end_define

begin_comment
comment|/* bytes/sector */
end_comment

begin_define
define|#
directive|define
name|MAXSEC
value|20480
end_define

begin_comment
comment|/* sectors/rl02 */
end_comment

begin_comment
comment|/*  * STXCS bit definitions  */
end_comment

begin_define
define|#
directive|define
name|STXCS_RDY
value|0x00000080
end_define

begin_comment
comment|/* ready bit */
end_comment

begin_define
define|#
directive|define
name|STXCS_IE
value|0x00000040
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|CRLERRS
value|5
end_define

begin_comment
comment|/* number of retries before quitting */
end_comment

begin_comment
comment|/*  * The state byte is used to retain exclusivity,  * and contains the busy flag.  */
end_comment

begin_define
define|#
directive|define
name|CRL_IDLE
value|0
end_define

begin_define
define|#
directive|define
name|CRL_OPEN
value|1
end_define

begin_define
define|#
directive|define
name|CRL_BUSY
value|2
end_define

begin_define
define|#
directive|define
name|CRLDS_BITS
define|\
value|"\20\20WDE\17CHE\16WL\15SKTO\14SPE\13WGE\12VC\11DSE\ \10DT\7HS\6CO\5HO\4BH\3STC\2STB\1STA"
end_define

begin_define
define|#
directive|define
name|CRLCS_BITS
define|\
value|"\20\20CE\17DE\16NXM\15DLT\14DCRC\13OPI\1DRDY"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

