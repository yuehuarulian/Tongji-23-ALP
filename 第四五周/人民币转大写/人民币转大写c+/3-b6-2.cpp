//–≈04 2252941 —Ó»¡È
#include <iostream>
using namespace std;

int main()
{
	double a;
	long long int z, x;
	long long int sy, y, qw, bw, sw, w, q, b, s, yuan, jiao, fen;
	cout << "«Î ‰»Î[0-100“⁄)÷Æº‰µƒ ˝◊÷:" << endl;
	cin >> a;
	z = (long long int)(a);
	x = (long long int)((a - z) * 100 + 0.5);
	sy = z / 1000000000;
	y = z % 1000000000 / 100000000;
	qw = z % 100000000 / 10000000;
	bw = z % 10000000 / 1000000;
	sw = z % 1000000 / 100000;
	w = z % 100000 / 10000;
	q = z % 10000 / 1000;
	b = z % 1000 / 100;
	s = z % 100 / 10;
	yuan = z % 10;
	jiao = x / 10;
	fen = x % 10;
	cout << "¥Û–¥Ω·π˚ «:" << endl;

	// Æ“⁄Œª ‰≥ˆ
	if (sy == 1)
		cout << "“º ∞";
	else if (sy == 2)
		cout << "∑° ∞";
	else if (sy == 3)
		cout << "»˛ ∞";
	else if (sy == 4)
		cout << "À¡ ∞";
	else if (sy == 5)
		cout << "ŒÈ ∞";
	else if (sy == 6)
		cout << "¬Ω ∞";
	else if (sy == 7)
		cout << "∆‚ ∞";
	else if (sy == 8)
		cout << "∞∆ ∞";
	else if (sy == 9)
		cout << "æ¡ ∞";

	//“⁄Œª ‰≥ˆ
	if (y == 0 && sy != 0)
		cout << "“⁄";
	else if (y == 1)
		cout << "“º“⁄";
	else if (y == 2)
		cout << "∑°“⁄";
	else if (y == 3)
		cout << "»˛“⁄";
	else if (y == 4)
		cout << "À¡“⁄";
	else if (y == 5)
		cout << "ŒÈ“⁄";
	else if (y == 6)
		cout << "¬Ω“⁄";
	else if (y == 7)
		cout << "∆‚“⁄";
	else if (y == 8)
		cout << "∞∆“⁄";
	else if (y == 9)
		cout << "æ¡“⁄";

	//«ßÕÚŒª ‰≥ˆ
	if (((sy + y) != 0) && ((bw + sw + w) != 0) && qw == 0)
		cout << "¡„";
	else if (qw == 1)
		cout << "“º«™";
	else if (qw == 2)
		cout << "∑°«™";
	else if (qw == 3)
		cout << "»˛«™";
	else if (qw == 4)
		cout << "À¡«™";
	else if (qw == 5)
		cout << "ŒÈ«™";
	else if (qw == 6)
		cout << "¬Ω«™";
	else if (qw == 7)
		cout << "∆‚«™";
	else if (qw == 8)
		cout << "∞∆«™";
	else if (qw == 9)
		cout << "æ¡«™";

	//∞ŸÕÚŒª ‰≥ˆ
	if ((qw != 0 && bw == 0) && (sw != 0 || w != 0) && bw == 0)
	{
		cout << "¡„";
	}
	else if (bw == 1)
		cout << "“º∞€";
	else if (bw == 2)
		cout << "∑°∞€";
	else if (bw == 3)
		cout << "»˛∞€";
	else if (bw == 4)
		cout << "À¡∞€";
	else if (bw == 5)
		cout << "ŒÈ∞€";
	else if (bw == 6)
		cout << "¬Ω∞€";
	else if (bw == 7)
		cout << "∆‚∞€";
	else if (bw == 8)
		cout << "∞∆∞€";
	else if (bw == 9)
		cout << "æ¡∞€";

	// ÆÕÚ ‰≥ˆ
	if ((sw == 0 && bw != 0) && w != 0)
	{
		cout << "¡„";
	}
	else if (sw == 1)
		cout << "“º ∞";
	else if (sw == 2)
		cout << "∑° ∞";
	else if (sw == 3)
		cout << "»˛ ∞";
	else if (sw == 4)
		cout << "À¡ ∞";
	else if (sw == 5)
		cout << "ŒÈ ∞";
	else if (sw == 6)
		cout << "¬Ω ∞";
	else if (sw == 7)
		cout << "∆‚ ∞";
	else if (sw == 8)
		cout << "∞∆ ∞";
	else if (sw == 9)
		cout << "æ¡ ∞";

	//ÕÚŒª ‰≥ˆ
	if (w == 0 && (qw != 0 || bw != 0 || sw != 0))
	{
		cout << "ÕÚ";
	}
	else if (w == 1)
		cout << "“ºÕÚ";
	else if (w == 2)
		cout << "∑°ÕÚ";
	else if (w == 3)
		cout << "»˛ÕÚ";
	else if (w == 4)
		cout << "À¡ÕÚ";
	else if (w == 5)
		cout << "ŒÈÕÚ";
	else if (w == 6)
		cout << "¬ΩÕÚ";
	else if (w == 7)
		cout << "∆‚ÕÚ";
	else if (w == 8)
		cout << "∞∆ÕÚ";
	else if (w == 9)
		cout << "æ¡ÕÚ";

	//«ßŒª ‰≥ˆ
	if (((sy + y + qw + bw + sw + w) != 0) && ((b + s + yuan) != 0) && q == 0)
		cout << "¡„";
	else if (q == 1)
		cout << "“º«™";
	else if (q == 2)
		cout << "∑°«™";
	else if (q == 3)
		cout << "»˛«™";
	else if (q == 4)
		cout << "À¡«™";
	else if (q == 5)
		cout << "ŒÈ«™";
	else if (q == 6)
		cout << "¬Ω«™";
	else if (q == 7)
		cout << "∆‚«™";
	else if (q == 8)
		cout << "∞∆«™";
	else if (q == 9)
		cout << "æ¡«™";

	//∞ŸŒª ‰≥ˆ
	if ((b == 0 && q != 0) && (s != 0 || yuan != 0))
	{
		cout << "¡„";
	}
	else if (b == 1)
		cout << "“º∞€";
	else if (b == 2)
		cout << "∑°∞€";
	else if (b == 3)
		cout << "»˛∞€";
	else if (b == 4)
		cout << "À¡∞€";
	else if (b == 5)
		cout << "ŒÈ∞€";
	else if (b == 6)
		cout << "¬Ω∞€";
	else if (b == 7)
		cout << "∆‚∞€";
	else if (b == 8)
		cout << "∞∆∞€";
	else if (b == 9)
		cout << "æ¡∞€";

	// ÆŒª ‰≥ˆ
	if ((s == 0 && b != 0) && yuan != 0)
	{
		cout << "¡„";
	}
	else if (s == 1)
		cout << "“º ∞";
	else if (s == 2)
		cout << "∑° ∞";
	else if (s == 3)
		cout << "»˛ ∞";
	else if (s == 4)
		cout << "À¡ ∞";
	else if (s == 5)
		cout << "ŒÈ ∞";
	else if (s == 6)
		cout << "¬Ω ∞";
	else if (s == 7)
		cout << "∆‚ ∞";
	else if (s == 8)
		cout << "∞∆ ∞";
	else if (s == 9)
		cout << "æ¡ ∞";


	//∏ˆŒª ‰≥ˆ
	if ((yuan == 0) && (sy + y + qw + bw + sw + w + q + b + s) != 0)
	{
		cout << "‘≤";
	}
	else if (yuan == 1)
		cout << "“º‘≤";
	else if (yuan == 2)
		cout << "∑°‘≤";
	else if (yuan == 3)
		cout << "»˛‘≤";
	else if (yuan == 4)
		cout << "À¡‘≤";
	else if (yuan == 5)
		cout << "ŒÈ‘≤";
	else if (yuan == 6)
		cout << "¬Ω‘≤";
	else if (yuan == 7)
		cout << "∆‚‘≤";
	else if (yuan == 8)
		cout << "∞∆‘≤";
	else if (yuan == 9)
		cout << "æ¡‘≤";

	//Ω« ‰≥ˆ
	if (((jiao + fen) == 0) && (sy + y + qw + bw + sw + w + q + b + s + yuan) != 0)
		cout << "’˚";
	else if ((jiao + fen) == 0)
		cout << "¡„‘≤’˚";
	else if (jiao == 0 && ((sy + y + qw + bw + sw + w + q + b + s + yuan) != 0))
		cout << "¡„";
	else if (jiao == 1)
		cout << "“ºΩ«";
	else if (jiao == 2)
		cout << "∑°Ω«";
	else if (jiao == 3)
		cout << "»˛Ω«";
	else if (jiao == 4)
		cout << "À¡Ω«";
	else if (jiao == 5)
		cout << "ŒÈΩ«";
	else if (jiao == 6)
		cout << "¬ΩΩ«";
	else if (jiao == 7)
		cout << "∆‚Ω«";
	else if (jiao == 8)
		cout << "∞∆Ω«";
	else if (jiao == 9)
		cout << "æ¡Ω«";

	//∑÷ ‰≥ˆ
	if (fen == 0 && jiao != 0)
		cout << "’˚";
	else if (fen == 1)
		cout << "“º∑÷";
	else if (fen == 2)
		cout << "∑°∑÷";
	else if (fen == 3)
		cout << "»˛∑÷";
	else if (fen == 4)
		cout << "À¡∑÷";
	else if (fen == 5)
		cout << "ŒÈ∑÷";
	else if (fen == 6)
		cout << "¬Ω∑÷";
	else if (fen == 7)
		cout << "∆‚∑÷";
	else if (fen == 8)
		cout << "∞∆∑÷";
	else if (fen == 9)
		cout << "æ¡∑÷";
	cout << endl;

	return 0;
}
