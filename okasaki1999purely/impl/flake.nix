{
  description = "A very basic haskell flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self,
    nixpkgs,
    utils,
    ...
  }:
    utils.lib.eachDefaultSystem (system: let
      pkgs = nixpkgs.legacyPackages.${system};
      haskellPackages = pkgs.haskellPackages;
      overlay = final: prev: {
        hs-example =
          haskellPackages.callCabal2nix "hs-example" ./. {};
      };
      myHaskellPackages = haskellPackages.extend overlay;
    in {
      devShell = myHaskellPackages.shellFor {
        packages = p: [
          p.hs-example
        ];
        nativeBuildInputs = with haskellPackages; [
          ghcid
          cabal-install
          haskell-language-server
          hspec-discover
        ];
      };

      packages = rec {
        hs-example = myHaskellPackages.hs-example;
        default = hs-example;
      };

      app = rec {
        hs-example = myHaskellPackages.hs-example;
        default = hs-example;
      };
    });
}
