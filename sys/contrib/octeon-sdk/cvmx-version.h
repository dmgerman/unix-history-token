begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Version information is made available at compile time in two forms: ** 1) a version string for printing ** 2) a combined SDK version and build number, suitable for comparisons **    to determine what SDK version is being used. **    SDK 1.2.3 build 567 => 102030567 **    Note that 2 digits are used for each version number, so that: **     1.9.0  == 01.09.00< 01.10.00 == 1.10.0  **     10.9.0 == 10.09.00> 09.10.00 == 9.10.0  **  */
end_comment

begin_define
define|#
directive|define
name|OCTEON_SDK_VERSION_NUM
value|109000312ull
end_define

begin_define
define|#
directive|define
name|OCTEON_SDK_VERSION_STRING
value|"Cavium Networks Octeon SDK version 1.9.0, build 312"
end_define

end_unit

