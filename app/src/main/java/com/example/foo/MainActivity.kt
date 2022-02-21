package com.example.foo

import android.annotation.SuppressLint
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.google.android.material.snackbar.Snackbar

class MainActivity : AppCompatActivity() {

    @SuppressLint("SetTextI18n")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val button = findViewById<TextView>(R.id.text)
        button.apply {
            text = "CLICK ME TO EXECUTE:\nSystem.loadLibrary(\"foo\")\nSystem.loadLibrary(\"bar\")"
            setOnClickListener {
                System.loadLibrary("foo")
                System.loadLibrary("bar")

                functionOfLibraryFoo()

                Snackbar.make(button, "Code executed, please see output of logcat", Snackbar.LENGTH_LONG).show()
            }
        }
    }

    companion object {

        @JvmStatic
        external fun functionOfLibraryFoo()
    }
}