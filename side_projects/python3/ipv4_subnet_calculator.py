import re

g_IPv4_NORMAL_FORM = ''''''

class IPv4:
    @classmethod
    def loopback(cls):
        return cls("127.0.0.1", "4")

    def __init__(self, ipv4: str, subnet:str):
        self.ipv4 = ipv4
        self.subm = subnet

def getInput() -> IPv4:
    raw = input("Network: ")
    prefix = re.search(raw, "\\d\\d?\\d?\\.\\d\\d?\\d?\\.\\d\\d?\\d?\\.\\d\\d?\\d?\\/\\d\\d?")
    normal = re.search(raw, "\\d\\d?\\d?\\.\\d\\d?\\d?\\.\\d\\d?\\d?\\.\\d\\d?\\d?")

    if prefix:
        subnet = raw.split('/')[1]
        return IPv4(raw.split('/')[0], subnet)
    else:
        if normal:
            subnet = input("Subnet Mask (Classful Form): ")
            return IPv4(normal.group(0), subnet)
    return IPv4.loopback()

if __name__ == "__main__":
    network = input("Network: ")
