begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Structure for the KSI/Odetics TPRO-S data returned in reponse to a  * read() call. Note that these are driver-specific and not dependent on  * 32/64-bit architecture.  */
end_comment

begin_struct
struct|struct
name|tproval
block|{
name|u_short
name|day100
decl_stmt|;
comment|/* days * 100 */
name|u_short
name|day10
decl_stmt|;
comment|/* days * 10 */
name|u_short
name|day1
decl_stmt|;
comment|/* days * 1 */
name|u_short
name|hour10
decl_stmt|;
comment|/* hours * 10 */
name|u_short
name|hour1
decl_stmt|;
comment|/* hours * 1 */
name|u_short
name|min10
decl_stmt|;
comment|/* minutes * 10 */
name|u_short
name|min1
decl_stmt|;
comment|/* minutes * 1 */
name|u_short
name|sec10
decl_stmt|;
comment|/* seconds * 10 */
name|u_short
name|sec1
decl_stmt|;
comment|/* seconds * 1*/
name|u_short
name|ms100
decl_stmt|;
comment|/* milliseconds * 100 */
name|u_short
name|ms10
decl_stmt|;
comment|/* milliseconds * 10 */
name|u_short
name|ms1
decl_stmt|;
comment|/* milliseconds * 1 */
name|u_short
name|usec100
decl_stmt|;
comment|/* microseconds * 100 */
name|u_short
name|usec10
decl_stmt|;
comment|/* microseconds * 10 */
name|u_short
name|usec1
decl_stmt|;
comment|/* microseconds * 1 */
name|long
name|tv_sec
decl_stmt|;
comment|/* seconds */
name|long
name|tv_usec
decl_stmt|;
comment|/* microseconds	*/
name|u_short
name|status
decl_stmt|;
comment|/* status register */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Status register bits  */
end_comment

begin_define
define|#
directive|define
name|TIMEAVAIL
value|0x0001
end_define

begin_comment
comment|/* time available */
end_comment

begin_define
define|#
directive|define
name|NOSIGNAL
value|0x0002
end_define

begin_comment
comment|/* insufficient IRIG-B signal */
end_comment

begin_define
define|#
directive|define
name|NOSYNC
value|0x0004
end_define

begin_comment
comment|/* local oscillator not synchronized */
end_comment

begin_comment
comment|/* end of tpro.h */
end_comment

end_unit

