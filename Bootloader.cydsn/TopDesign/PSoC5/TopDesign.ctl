-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-050 PSoC5 kit.
-- =============================================================================

-- === USBFS ===
attribute port_location of \USBFS:Dp(0)\ : label is "PORT(15,6)";
attribute port_location of \USBFS:Dm(0)\ : label is "PORT(15,7)";


-- === LED4 ===
attribute port_location of LED4(0) : label is "PORT(6,3)";