begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_ST_PINCFG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ST_PINCFG_H_
end_define

begin_comment
comment|/* Alternate functions */
end_comment

begin_define
define|#
directive|define
name|ALT1
value|1
end_define

begin_define
define|#
directive|define
name|ALT2
value|2
end_define

begin_define
define|#
directive|define
name|ALT3
value|3
end_define

begin_define
define|#
directive|define
name|ALT4
value|4
end_define

begin_define
define|#
directive|define
name|ALT5
value|5
end_define

begin_define
define|#
directive|define
name|ALT6
value|6
end_define

begin_define
define|#
directive|define
name|ALT7
value|7
end_define

begin_comment
comment|/* Output enable */
end_comment

begin_define
define|#
directive|define
name|OE
value|(1<< 27)
end_define

begin_comment
comment|/* Pull Up */
end_comment

begin_define
define|#
directive|define
name|PU
value|(1<< 26)
end_define

begin_comment
comment|/* Open Drain */
end_comment

begin_define
define|#
directive|define
name|OD
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RT
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|INVERTCLK
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|CLKNOTDATA
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|DOUBLE_EDGE
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|CLK_A
value|(0<< 18)
end_define

begin_define
define|#
directive|define
name|CLK_B
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|CLK_C
value|(2<< 18)
end_define

begin_define
define|#
directive|define
name|CLK_D
value|(3<< 18)
end_define

begin_comment
comment|/* User-frendly defines for Pin Direction */
end_comment

begin_comment
comment|/* oe = 0, pu = 0, od = 0 */
end_comment

begin_define
define|#
directive|define
name|IN
value|(0)
end_define

begin_comment
comment|/* oe = 0, pu = 1, od = 0 */
end_comment

begin_define
define|#
directive|define
name|IN_PU
value|(PU)
end_define

begin_comment
comment|/* oe = 1, pu = 0, od = 0 */
end_comment

begin_define
define|#
directive|define
name|OUT
value|(OE)
end_define

begin_comment
comment|/* oe = 1, pu = 0, od = 1 */
end_comment

begin_define
define|#
directive|define
name|BIDIR
value|(OE | OD)
end_define

begin_comment
comment|/* oe = 1, pu = 1, od = 1 */
end_comment

begin_define
define|#
directive|define
name|BIDIR_PU
value|(OE | PU | OD)
end_define

begin_comment
comment|/* RETIME_TYPE */
end_comment

begin_comment
comment|/*  * B Mode  * Bypass retime with optional delay parameter  */
end_comment

begin_define
define|#
directive|define
name|BYPASS
value|(0)
end_define

begin_comment
comment|/*  * R0, R1, R0D, R1D modes  * single-edge data non inverted clock, retime data with clk  */
end_comment

begin_define
define|#
directive|define
name|SE_NICLK_IO
value|(RT)
end_define

begin_comment
comment|/*  * RIV0, RIV1, RIV0D, RIV1D modes  * single-edge data inverted clock, retime data with clk  */
end_comment

begin_define
define|#
directive|define
name|SE_ICLK_IO
value|(RT | INVERTCLK)
end_define

begin_comment
comment|/*  * R0E, R1E, R0ED, R1ED modes  * double-edge data, retime data with clk  */
end_comment

begin_define
define|#
directive|define
name|DE_IO
value|(RT | DOUBLE_EDGE)
end_define

begin_comment
comment|/*  * CIV0, CIV1 modes with inverted clock  * Retiming the clk pins will park clock& reduce the noise within the core.  */
end_comment

begin_define
define|#
directive|define
name|ICLK
value|(RT | CLKNOTDATA | INVERTCLK)
end_define

begin_comment
comment|/*  * CLK0, CLK1 modes with non-inverted clock  * Retiming the clk pins will park clock& reduce the noise within the core.  */
end_comment

begin_define
define|#
directive|define
name|NICLK
value|(RT | CLKNOTDATA)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ST_PINCFG_H_ */
end_comment

end_unit

