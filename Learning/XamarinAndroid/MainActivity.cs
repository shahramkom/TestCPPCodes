using Android.App;
using Android.OS;
using Android.Support.V7.App;
using Android.Runtime;
using Android.Widget;

namespace XamarinAndroid
{
    [Activity(Label = "@string/app_name", Theme = "@style/AppTheme", MainLauncher = true)]
    public class MainActivity : AppCompatActivity
    {
        protected override void OnCreate(Bundle savedInstanceState)
        {
            base.OnCreate(savedInstanceState);
            // Set our view from the "main" layout resource
            SetContentView(Resource.Layout.activity_main);
            TextView phoneNumberText = FindViewById<TextView>(Resource.Id.PhoneNumberText);
            EditText translatedPhoneWord = FindViewById<EditText>(id: Resource.Id.translatedPhoneWord);
            Button translateButton = FindViewById<Button>(Resource.Id.TranslateButton);
            translateButton.Click += (sender, e) =>
            {
                // Translate user's alphanumeric phone number to numeric
                string translatedNumber = Core.PhonewordTranslator.ToNumber(phoneNumberText.Text);
                if (string.IsNullOrWhiteSpace(translatedNumber))
                    translatedPhoneWord.Text = string.Empty;
                else
                    translatedPhoneWord.Text = translatedNumber;
            };
        }
    }
}