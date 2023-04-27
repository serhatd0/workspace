import can

# CAN arabiriminin oluşturulması
bus = can.interface.Bus(bustype='socketcan', channel='can0', bitrate=250000)

# CAN mesajının oluşturulması
can_data = [0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08]
can_msg = can.Message(arbitration_id=0x123, data=can_data, is_extended_id=False)

# CAN mesajının gönderilmesi
try:
    bus.send(can_msg)
    print("CAN mesajı gönderildi")
except can.CanError:
    print("CAN hatası oluştu")