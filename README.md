# Authdeez

Authdeez it's an (experimental) authenticator (like Google Authenticator) for desktops systems, that uses [HOTP](https://www.rfc-editor.org/rfc/rfc4226)/[TOTP](https://datatracker.ietf.org/doc/html/rfc6238) Algorithm to generate temporary passcodes to 2factor authentication.

## Dependencies

Openssl (libcrypto)

## Compilling

```
meson subprojects download
meson setup build
meson compile -C build
```

## Testing

After compiling, you can find all tests in `./build/all_tests` (quite intuitive huh?).

## Running

Check accounts.example.txt for store keys in a file and rename it to `accounts.txt`.

Run with `./build/authdeez/`.

## Example 

[![asciicast](https://asciinema.org/a/lobBsF6thxhBKq2GysMqOoV4f.svg)](https://asciinema.org/a/lobBsF6thxhBKq2GysMqOoV4f)

## Milestones

- [ ] Better Cli usage
- [ ] Configuration File with default location
- [ ] Release Binaries
- [ ] Protect accounts.txt with a password
- [ ] GUI

