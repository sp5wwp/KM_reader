# KM_reader
QR code content decoder for *Koleje Mazowieckie* tickets. Reads 32 bytes passed through `stdin`.

## Building
Run `make` in the main directory.

## Example use
Scan the QR code and pass the base64 encoded string to `read`:
```bash
echo -n "AwIgS0NCtoYMAkAAHwBMABZvlxsAxZcb/1G/G+MIqQAwMDAwMDAwMDAwMC4CFQDNMsZglOkHejIUGWVZekHqkl9xswIVAJhDtEW94KCZ4y33Ybjwx32AE0mY" | base64 -d | ./read
```

Running this command should result with:

```text
NUMER:	CK0210155074
CENA:	163.86
OF:     31
ULGA:	76
KUPNO:	01-09-2024, 17:53:26
POCZ.:	02-09-2024, 00:00:00
KON.:	01-10-2024, 23:59:59
OD:     2275
DO:     169
```

## Note
The base64 string obtained from the QR code decodes to more than 32 bytes, but the meaning of the remaining data is unknown. Most likely, it's some form of hash or signature to prevent ticket faking.
