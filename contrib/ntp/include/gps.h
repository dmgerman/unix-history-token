begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*      gps.h                                                            */
end_comment

begin_comment
comment|/*      TrueTime GPS-VME and VME-SG                                     */
end_comment

begin_comment
comment|/*      VME controller hardware commands and parameters.                */
end_comment

begin_comment
comment|/*      created 010694 res                                              */
end_comment

begin_comment
comment|/*      History:        revised for 747i 3/94                           */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|GPS_VME
value|"/dev/vme2"
end_define

begin_comment
comment|/* the device file for the GPS board */
end_comment

begin_comment
comment|/* change it to whatever yours is */
end_comment

begin_define
define|#
directive|define
name|PRIO
value|120
end_define

begin_comment
comment|/* set the realtime priority */
end_comment

begin_define
define|#
directive|define
name|NREGS
value|7
end_define

begin_comment
comment|/* number of registers we will use */
end_comment

begin_define
define|#
directive|define
name|GFRZ1
value|0x0020
end_define

begin_comment
comment|/* freeze cmd addr gen reg. 1 */
end_comment

begin_define
define|#
directive|define
name|GREG1A
value|0x0021
end_define

begin_comment
comment|/* Gen reg. 1 Word A (units microsec to 0.001 sec) */
end_comment

begin_define
define|#
directive|define
name|GREG1B
value|0x0040
end_define

begin_comment
comment|/* Gen reg. 1 Word B (units 0.01 sec to tens sec ) */
end_comment

begin_define
define|#
directive|define
name|GREG1C
value|0x0041
end_define

begin_comment
comment|/* Gen reg  1 Word C (units mins and hours) */
end_comment

begin_define
define|#
directive|define
name|GREG1D
value|0x0042
end_define

begin_comment
comment|/* Gen reg. 1 Word D (units days and status) */
end_comment

begin_define
define|#
directive|define
name|GREG1E
value|0x0043
end_define

begin_comment
comment|/* Gen reg. 1 Word E (units Years ) */
end_comment

begin_define
define|#
directive|define
name|GUFRZ1
value|0x0022
end_define

begin_comment
comment|/* unfreeze cmd addr gen reg 1 */
end_comment

begin_define
define|#
directive|define
name|MASKDAY
value|0x0FFF
end_define

begin_comment
comment|/* mask for units days */
end_comment

begin_define
define|#
directive|define
name|MASKHI
value|0xFF00
end_define

begin_define
define|#
directive|define
name|MASKLO
value|0x00FF
end_define

begin_comment
comment|/* Use the following ASCII hex values: N(0x004e),S(0x0053),E(0x0045),         W(0x0057), +(0x002B), - (0x002D)   */
end_comment

begin_define
define|#
directive|define
name|LAT1
value|0x0048
end_define

begin_comment
comment|/* Lat (degrees) */
end_comment

begin_define
define|#
directive|define
name|LAT2
value|0x0049
end_define

begin_comment
comment|/* Lat (min, sec) */
end_comment

begin_define
define|#
directive|define
name|LAT3
value|0x004A
end_define

begin_comment
comment|/* Lat (N/S, tenths sec) */
end_comment

begin_define
define|#
directive|define
name|LON1
value|0x004B
end_define

begin_comment
comment|/* Lon (degrees) */
end_comment

begin_define
define|#
directive|define
name|LON2
value|0x004C
end_define

begin_comment
comment|/* Lon (min, sec) */
end_comment

begin_define
define|#
directive|define
name|LON3
value|0x004D
end_define

begin_comment
comment|/* Lon (E/W, tenths sec) */
end_comment

begin_define
define|#
directive|define
name|ELV1
value|0x004E
end_define

begin_comment
comment|/* Elev. (sign, 10,000 and 1000 ) */
end_comment

begin_define
define|#
directive|define
name|ELV2
value|0x004F
end_define

begin_comment
comment|/* Elev. (100, 10s, units, and .1) */
end_comment

begin_define
define|#
directive|define
name|CFREG1
value|0x0050
end_define

begin_comment
comment|/* config. register 1 */
end_comment

begin_define
define|#
directive|define
name|CFREG2
value|0x00A0
end_define

begin_comment
comment|/* config. register 2 */
end_comment

begin_define
define|#
directive|define
name|PMODE
value|0x00A4
end_define

begin_comment
comment|/* Position mode */
end_comment

begin_define
define|#
directive|define
name|LOCAL
value|0x0051
end_define

begin_comment
comment|/* Local hours offset */
end_comment

begin_define
define|#
directive|define
name|RATE
value|0x0054
end_define

begin_comment
comment|/* Pulse rate output select */
end_comment

begin_define
define|#
directive|define
name|DAC
value|0x0055
end_define

begin_comment
comment|/* OSC Control (DAC) select */
end_comment

begin_define
define|#
directive|define
name|PUMS
value|0x0056
end_define

begin_comment
comment|/* Gen. preset register unit millisec */
end_comment

begin_define
define|#
directive|define
name|PMS
value|0x0057
end_define

begin_comment
comment|/* Gen. preset register units hundreds and tens ms */
end_comment

begin_define
define|#
directive|define
name|PSEC
value|0x0058
end_define

begin_comment
comment|/* Gen. preset register units tens and unit seconds */
end_comment

begin_define
define|#
directive|define
name|PMIN
value|0x0059
end_define

begin_comment
comment|/* Gen. preset register units tens and unit minutes */
end_comment

begin_define
define|#
directive|define
name|PHRS
value|0x005A
end_define

begin_comment
comment|/* Gen. preset register units tens and unit hours */
end_comment

begin_define
define|#
directive|define
name|PDYS1
value|0x005B
end_define

begin_comment
comment|/* Gen. preset register units tens and unit days */
end_comment

begin_define
define|#
directive|define
name|PDYS2
value|0x005C
end_define

begin_comment
comment|/* Gen. preset register units hundreds days */
end_comment

begin_define
define|#
directive|define
name|PYRS1
value|0x005D
end_define

begin_comment
comment|/* Gen. preset register units tens and unit years */
end_comment

begin_define
define|#
directive|define
name|PYRS2
value|0x005E
end_define

begin_comment
comment|/* Gen. preset reg. units thousands and hundreds yrs */
end_comment

end_unit

