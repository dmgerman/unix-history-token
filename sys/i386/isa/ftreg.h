begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1993, 1994 Steve Gerakines  *  *  This is freely redistributable software.  You may do anything you  *  wish with it, so long as the above notice stays intact.  *  *  THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS  *  OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  *  DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT,  *  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  *  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  *  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  *  ftreg.h - QIC-40/80 floppy tape driver header  *  06/03/94 v0.9  *  Changed seek load point to QC_SEEKLP, added reqseg to SegReq structure.  *  *  10/30/93 v0.3  *  More things will end up here.  QC_VENDORID and QC_VERSION now used.  *  *  08/07/93 v0.2 release  *  Things that should've been here in the first place were moved.  *  Tape geometry and segment request types were added.  *  *  06/03/93 v0.1 Alpha release  *  Initial revision.  Many more things should be moved here.  */
end_comment

begin_comment
comment|/* QIC-117 command set. */
end_comment

begin_define
define|#
directive|define
name|QC_RESET
value|1
end_define

begin_comment
comment|/* reset */
end_comment

begin_define
define|#
directive|define
name|QC_NEXTBIT
value|2
end_define

begin_comment
comment|/* report next bit */
end_comment

begin_define
define|#
directive|define
name|QC_PAUSE
value|3
end_define

begin_comment
comment|/* pause */
end_comment

begin_define
define|#
directive|define
name|QC_STPAUSE
value|4
end_define

begin_comment
comment|/* step pause */
end_comment

begin_define
define|#
directive|define
name|QC_TIMEOUT
value|5
end_define

begin_comment
comment|/* alt timeout */
end_comment

begin_define
define|#
directive|define
name|QC_STATUS
value|6
end_define

begin_comment
comment|/* report status */
end_comment

begin_define
define|#
directive|define
name|QC_ERRCODE
value|7
end_define

begin_comment
comment|/* report error code */
end_comment

begin_define
define|#
directive|define
name|QC_CONFIG
value|8
end_define

begin_comment
comment|/* report config */
end_comment

begin_define
define|#
directive|define
name|QC_VERSION
value|9
end_define

begin_comment
comment|/* report version */
end_comment

begin_define
define|#
directive|define
name|QC_FORWARD
value|10
end_define

begin_comment
comment|/* logical forward */
end_comment

begin_define
define|#
directive|define
name|QC_SEEKSTART
value|11
end_define

begin_comment
comment|/* seek to track start */
end_comment

begin_define
define|#
directive|define
name|QC_SEEKEND
value|12
end_define

begin_comment
comment|/* seek to track end */
end_comment

begin_define
define|#
directive|define
name|QC_SEEKTRACK
value|13
end_define

begin_comment
comment|/* seek head to track */
end_comment

begin_define
define|#
directive|define
name|QC_SEEKLP
value|14
end_define

begin_comment
comment|/* seek load point */
end_comment

begin_define
define|#
directive|define
name|QC_FORMAT
value|15
end_define

begin_comment
comment|/* format mode */
end_comment

begin_define
define|#
directive|define
name|QC_WRITEREF
value|16
end_define

begin_comment
comment|/* write reference */
end_comment

begin_define
define|#
directive|define
name|QC_VERIFY
value|17
end_define

begin_comment
comment|/* verify mode */
end_comment

begin_define
define|#
directive|define
name|QC_STOP
value|18
end_define

begin_comment
comment|/* stop tape */
end_comment

begin_define
define|#
directive|define
name|QC_STEPUP
value|21
end_define

begin_comment
comment|/* step head up */
end_comment

begin_define
define|#
directive|define
name|QC_STEPDOWN
value|22
end_define

begin_comment
comment|/* step head down */
end_comment

begin_define
define|#
directive|define
name|QC_SEEKREV
value|25
end_define

begin_comment
comment|/* seek reverse */
end_comment

begin_define
define|#
directive|define
name|QC_SEEKFWD
value|26
end_define

begin_comment
comment|/* seek forward */
end_comment

begin_define
define|#
directive|define
name|QC_RATE
value|27
end_define

begin_comment
comment|/* select data rate */
end_comment

begin_define
define|#
directive|define
name|QC_DIAG1
value|28
end_define

begin_comment
comment|/* diagnostic mode 1 */
end_comment

begin_define
define|#
directive|define
name|QC_DIAG2
value|29
end_define

begin_comment
comment|/* diagnostic mode 2 */
end_comment

begin_define
define|#
directive|define
name|QC_PRIMARY
value|30
end_define

begin_comment
comment|/* primary mode */
end_comment

begin_define
define|#
directive|define
name|QC_VENDORID
value|32
end_define

begin_comment
comment|/* vendor id */
end_comment

begin_define
define|#
directive|define
name|QC_TSTATUS
value|33
end_define

begin_comment
comment|/* report tape status */
end_comment

begin_define
define|#
directive|define
name|QC_EXTREV
value|34
end_define

begin_comment
comment|/* extended skip reverse */
end_comment

begin_define
define|#
directive|define
name|QC_EXTFWD
value|35
end_define

begin_comment
comment|/* extended skip forward */
end_comment

begin_comment
comment|/* Colorado enable/disable. */
end_comment

begin_define
define|#
directive|define
name|QC_COL_ENABLE1
value|46
end_define

begin_comment
comment|/* enable */
end_comment

begin_define
define|#
directive|define
name|QC_COL_ENABLE2
value|2
end_define

begin_comment
comment|/* unit+2 */
end_comment

begin_define
define|#
directive|define
name|QC_COL_DISABLE
value|47
end_define

begin_comment
comment|/* disable */
end_comment

begin_comment
comment|/* Mountain enable/disable. */
end_comment

begin_define
define|#
directive|define
name|QC_MTN_ENABLE1
value|23
end_define

begin_comment
comment|/* enable 1 */
end_comment

begin_define
define|#
directive|define
name|QC_MTN_ENABLE2
value|20
end_define

begin_comment
comment|/* enable 2 */
end_comment

begin_define
define|#
directive|define
name|QC_MTN_DISABLE
value|24
end_define

begin_comment
comment|/* disable */
end_comment

begin_comment
comment|/* Segment I/O request. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|segq
block|{
name|unsigned
name|char
name|buff
index|[
name|QCV_SEGSIZE
index|]
decl_stmt|;
comment|/* Segment data; first for alignment */
name|int
name|reqtype
decl_stmt|;
comment|/* Request type */
name|long
name|reqcrc
decl_stmt|;
comment|/* CRC Errors found */
name|long
name|reqbad
decl_stmt|;
comment|/* Bad sector map */
name|long
name|reqblk
decl_stmt|;
comment|/* Block request starts at */
name|long
name|reqseg
decl_stmt|;
comment|/* Segment request is at */
name|int
name|reqcan
decl_stmt|;
comment|/* Cancel read-ahead */
name|struct
name|segq
modifier|*
name|next
decl_stmt|;
comment|/* Next request */
block|}
name|SegReq
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ftu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ftsu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ft_data
modifier|*
name|ft_p
typedef|;
end_typedef

end_unit

